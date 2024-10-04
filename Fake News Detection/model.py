import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
import gensim
from keras.preprocessing.text import Tokenizer
from keras.preprocessing.sequence import pad_sequences
from keras.models import Sequential
from keras.layers import Dense,Embedding,LSTM
from sklearn.model_selection import train_test_split

real_data=pd.read_csv("D:/coding/BTP/News_dataset/True.csv")
fake_data=pd.read_csv("D:/coding/BTP/News_dataset/Fake.csv")
real_data=real_data.drop(8970,axis=0)
unknown=[]
for index,row in enumerate(real_data.text.values):
    try:
        record=row.split(' - ',maxsplit=1)
        record[1]
        assert(len(record[0])<120)
    except:
        unknown.append(index)

publisher=[]
org_text=[]
for index,row in enumerate(real_data.text.values):
    if index in unknown:
        org_text.append(row)
        publisher.append('Unknown')
    else:
        record=row.split(' - ',maxsplit=1)
        publisher.append(record[0].strip())
        org_text.append(record[1].strip())

real_data['publisher']=publisher
real_data['text']=org_text
empty_fake_index=[index for index,text in enumerate(fake_data.text.tolist()) if str(text).strip()==""]
real_data['text']=real_data['title']+" "+real_data['text']
fake_data['text']=fake_data['title']+" "+fake_data['text']
fake_data['text']=fake_data['text'].apply(lambda x:str(x).lower())
real_data['text']=real_data['text'].apply(lambda x:str(x).lower())
real_data['class']=1
fake_data['class']=0
real_data=real_data[['text','class']]
fake_data=fake_data[['text','class']]
data=pd.concat([real_data,fake_data])
data=data.sample(frac=1).reset_index(drop=True)

for i in range(data.shape[0]):
    row=data.iloc(0)
    a=row[i].text
    a=''.join(letter for letter in a if (letter.isalnum() or letter==' '))
    data.loc[i,'text']=a

y=data['class'].values
x=[d.split() for d in data['text'].tolist()]

dim=100
w2v=gensim.models.Word2Vec(sentences=x,vector_size=dim,window=10,min_count=1)

tokenizer=Tokenizer()
tokenizer.fit_on_texts(x)
X=tokenizer.texts_to_sequences(x)

X=pad_sequences(X,maxlen=1000)
vocab_size=len(tokenizer.word_index)+1
vocab=tokenizer.word_index

def get_weight_matrix(model):
    weight_matrix=np.zeros((vocab_size,100))
    for word,i in vocab.items():
        weight_matrix[i]=model.wv[word]
    return weight_matrix

embedding_vector=get_weight_matrix(w2v)

model=Sequential()
model.add(Embedding(vocab_size,output_dim=100,weights=[embedding_vector],input_length=1000,trainable=False))
model.add(LSTM(units=128))
model.add(Dense(1,activation='sigmoid'))
model.compile(optimizer='adam',loss='binary_crossentropy',metrics=['acc'])

x_train,x_test,y_train,y_test=train_test_split(X,y)

model.fit(x_train,y_train,validation_split=0.3,epochs=2)

model_path = 'D:\\coding\\BTP\\model2.h5'
model.save(model_path)
print(f"Model saved successfully at: {model_path}")

# Save the Word2Vec model using Gensim's save method
w2v_path = 'D:\\coding\\BTP\\w2v_model2.bin'
w2v.save(w2v_path)
print(f"Word2Vec model saved successfully at: {w2v_path}")
