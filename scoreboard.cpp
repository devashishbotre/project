#include <iostream>
#include<cstring>
#include<string>

using namespace std;

struct team //team data
{
    string name;//team name
    int runs;//team total runs
    int overs;//overs played by a team
    int wickets;//wickets fallen of a team
    int balls;//balls in an over played
    int fours;//total fours hit
    int sixes;//total sixes hit
    float run_rate;
    string all_players_name[15];
    string team_starting_11_name[11];
    int individual_runs[11];
    int individual_balls_played[11];
    int individual_fours[11];
    int individual_sixes[11];
    float individual_strike_rate[11];
    int extras;//total extras given
    int runs_given;
    int overs_bowled;
    int balls_bowled;
    int wickets_taken;
    int dots;
    int drs;
};

void InputTeamName(struct team *x,string team)//give the team a name
{
    x->name=team;
}

void InputAllPlayers(struct team *x) //take all players present as input
{
    for(int i=0;i<15;i++)
    {
        cout<<"Enter the "<<i<<"th player name: ";
        getline(cin,x->all_players_name[i]);
    }
}

void DisplayAllPlayers(struct team *x) //display all list of players
{
    for(int i=0;i<15;i++)
    {
        cout<<x->all_players_name[i]<<endl;
    }
}

void InputStarting11(struct team *x) //take all player which will be playing
{
    for(int i=0;i<11;i++)
    {
        int j;
        cout<<"Enter the "<<i<<"th player name: ";
        cin>>j;
        x->team_starting_11_name[i]=x->all_players_name[j];//give index
    }
}

void DisplayStarting11(struct team *x) //display playing 11
{
    for(int i=0;i<11;i++)
    {
        cout<<x->team_starting_11_name[i]<<endl;//should be in the order of batting position
    }
}

void DisplayBattingScorecard(struct team *x) //show batting scorecard
{
    cout<<x->name<<endl;

    for(int i=1;i<=12;i++)
    {
        cout<<" ";
    }
    cout<<"Player";

    for(int i=1;i<=12;i++)
    {
        cout<<" ";
    }
    cout<<"|";
    cout<<" Runs |";
    cout<<" Balls |";
    cout<<" Fours |";
    cout<<" Sixes |";
    cout<<" Strike Rate "<<endl; //all data which will be shown

    for(int i=1;i<=30;i++)
    {
        cout<<"-";
    }
    cout<<"|------|-------|-------|-------|-------------"<<endl;

    for(int i=0;i<11;i++) //all 11 players to be put
    {
        int len=x->team_starting_11_name[i].size(); //defining length of players name
        cout<<x->team_starting_11_name[i];

        for(int j=1;j<=30-len;j++)
        {
            cout<<" ";
        }

        cout<<"|";

        cout<<x->individual_runs[i];
        if(x->individual_runs[i]<10)
        {
            cout<<"     |";
        }

        else if(x->individual_runs[i]<100)
        {
            cout<<"    |";
        }

        else if(x->individual_runs[i]<1000)
        {
            cout<<"   |";
        }

        else
        {
            cout<<"  |";
        }

        cout<<x->individual_balls_played[i];

        if(x->individual_balls_played[i]<10)
        {
            cout<<"      |";
        }

        else if(x->individual_balls_played[i]<100)
        {
            cout<<"     |";
        }

        else
        {
            cout<<"    |";
        }

        cout<<x->individual_fours[i];

        if(x->individual_fours[i]<10)
        {
            cout<<"      |";
        }

        else
        {
            cout<<"     |";
        }

        cout<<x->individual_sixes[i];

        if(x->individual_sixes[i]<10)
        {
            cout<<"      |";
        }

        else
        {
            cout<<"     |";
        }

        cout<<x->individual_strike_rate[i]<<endl;
    }

    for(int i=1;i<=30;i++)
    {
        cout<<"-";
    }
    cout<<"|------|-------|-------|-------|-------------"<<endl;

    cout<<"Extras: "<<x->extras;

    if(x->extras<10)
    {
        for(int i=1;i<=21;i++)
        {
            cout<<" ";
        }
    }

    else
    {
        for(int i=1;i<21;i++)
        {
            cout<<" ";
        }
    }
    cout<<"|";

    cout<<x->runs<<"-"<<x->wickets;

    if(x->runs<10 && x->wickets<10)
    {
        cout<<"   |";
    }

    else if((x->runs<100 && x->wickets<10) || (x->runs<10 && x->wickets==10))
    {
        cout<<"  |";
    }

    else if((x->runs<1000 && x->wickets<10) || (x->runs<100 && x->wickets==10))
    {
        cout<<" |";
    }

    else
    {
        cout<<"|";
    }

    cout<<x->overs<<"."<<x->balls;
    if(x->overs<10)
    {
        cout<<"    |";
    }

    else
    {
        cout<<"   |";
    }

    cout<<x->fours;

    if(x->fours<10)
    {
        cout<<"      |";
    }

    else
    {
        cout<<"     |";
    }

    cout<<x->sixes;

    if(x->sixes<10)
    {
        cout<<"      |";
    }

    else
    {
        cout<<"     |";
    }

    cout<<"RPO- "<<x->run_rate<<endl;
    cout<<endl;
}

void InitializeData(struct team *x)
{
    x->balls=0;
    x->extras=0;
    x->fours=0;
    x->overs=0;
    x->runs=0;
    x->sixes=0;
    x->wickets=0;
    x->run_rate=0;
    for(int i=0;i<11;i++){
        x->individual_runs[i]=0;
        x->individual_balls_played[i]=0;
        x->individual_fours[i]=0;
        x->individual_sixes[i]=0;
        x->individual_strike_rate[i]=0;}
    x->drs=2;
}
void UpdateBattingScorecard(string c,struct team *x,int *i,int *j)
{
    if(c=="0" || c=="1" || c=="2" || c=="3" || c=="4" || c=="5" || c=="6")
    {

        if(c=="1")
        {
            x->runs+=1;
            x->individual_runs[*i]+=1;
            x->individual_balls_played[*i]+=1;

            if(x->individual_balls_played[*i]==0){
                x->individual_strike_rate[*i]=0;}
            else{
                x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
            if(x->balls<5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"Single is taken."<<endl;
        }
        else if(c=="0")
        {
            x->individual_balls_played[*i]+=1;

            if(x->individual_balls_played[*i]==0){
                x->individual_strike_rate[*i]=0;}
            else{
                x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
            if(x->balls==5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"It's a dot ball"<<endl;
        }
        else if(c=="2")
        {
            x->runs+=2;
            x->individual_runs[*i]+=2;
            x->individual_balls_played[*i]+=1;

            if(x->individual_balls_played[*i]==0){
                x->individual_strike_rate[*i]=0;}
            else{
                x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
            if(x->balls==5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"Double is taken."<<endl;
        }
        else if(c=="3")
        {
            x->runs+=3;
            x->individual_runs[*i]+=3;
            x->individual_balls_played[*i]+=1;

            if(x->individual_balls_played[*i]==0){
                x->individual_strike_rate[*i]=0;}
            else{
                x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
            if(x->balls<5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"Both completed 3rd run.Good running."<<endl;
        }
        else if(c=="4")
        {
            x->runs+=4;
            x->individual_runs[*i]+=4;
            x->individual_balls_played[*i]+=1;

            if(x->individual_balls_played[*i]==0){
                x->individual_strike_rate[*i]=0;}
            else{
                x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
            x->fours+=1;
            x->individual_fours[*i]+=1;

            if(x->balls==5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"Excellent shot for four."<<endl;
        }
        else if(c=="6")
        {
            x->runs+=6;
            x->individual_runs[*i]+=6;
            x->individual_balls_played[*i]+=1;

            if(x->individual_balls_played[*i]==0){
                x->individual_strike_rate[*i]=0;}
            else{
                x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
            x->sixes+=1;
            x->individual_sixes[*i]+=1;

            if(x->balls==5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"That's huge for six."<<endl;
        }
        else
        {
            x->runs+=5;
            x->individual_runs[*i]+=5;
            x->individual_balls_played[*i]+=1;

            if(x->individual_balls_played[*i]==0){
                x->individual_strike_rate[*i]=0;}
            else{
                x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
            if(x->balls<5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"There's an overthrow and it is 4. 5 runs in a single delivery"<<endl;
        }

        if(x->balls==5)
        {
            x->overs+=1;
            x->balls=0;
            cout<<"End of the over."<<endl;
        }
        else
        {
            x->balls+=1;
        }
    }

    else if(c=="w")
    {
        x->runs+=1;
        x->extras+=1;
        cout<<"That's wide."<<endl;
    }

    else if(c=="w1")
    {
        x->runs+=2;
        x->extras+=2;
        int temp=*i;
        *i=*j;
        *j=temp;

        cout<<"That's wide. Wicketkeeper doesn't stop the ball and batsman takes a quick single too"<<endl;
    }

    else if(c=="w2")
    {
        x->runs+=3;
        x->extras+=3;
        cout<<"That's wide. Wicketkeeper doesn't stop the ball and both the batsman come back for two."<<endl;
    }

    else if(c=="w3")
    {
        x->runs+=4;
        x->extras+=4;
        int temp=*i;
        *i=*j;
        *j=temp;

        cout<<"That's wide. Wicketkeeper doesn't stop the ball and both the batsman come back for three. Bad fielding"<<endl;
    }

    else if(c=="w4")
    {
        x->runs+=5;
        x->extras+=5;
        cout<<"That's wide. Wicketkeeper doesn't stop the ball and it race away for four."<<endl;
    }

    else if(c=="n1")
    {
        x->runs+=2;
        x->extras+=1;
        x->individual_balls_played[*i]+=1;
        x->individual_runs[*i]+=1;
        if(x->individual_balls_played[*i]==0){
            x->individual_strike_rate[*i]=0;}
        else{
            x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
        int temp=*i;
        *i=*j;
        *j=temp;

        cout<<"It's no ball. Single is taken. Next ball is free hit."<<endl;
    }
    else if(c=="n2")
    {
        x->runs+=3;
        x->extras+=1;
        x->individual_balls_played[*i]+=1;
        x->individual_runs[*i]+=2;
        if(x->individual_balls_played[*i]==0){
            x->individual_strike_rate[*i]=0;}
        else{
            x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
            cout<<"It's no ball. Double is taken. Next ball is free hit."<<endl;
        }

    else if(c=="n3")
    {
        x->runs+=4;
        x->extras+=1;
        x->individual_balls_played[*i]+=1;
        x->individual_runs[*i]+=3;
        if(x->individual_balls_played[*i]==0){
            x->individual_strike_rate[*i]=0;}
        else{
            x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
        int temp=*i;
        *i=*j;
        *j=temp;

        cout<<"It's no ball. Both completed 3rd run.Good running.Next ball is free hit."<<endl;
        }

    else if(c=="n4")
    {
        x->runs+=5;
        x->extras+=1;
        x->individual_balls_played[*i]+=1;
        x->individual_runs[*i]+=4;
        if(x->individual_balls_played[*i]==0){
            x->individual_strike_rate[*i]=0;}
        else{
            x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
        x->fours+=1;
        x->individual_fours[*i]+=1;

        cout<<"It's no ball. Excellent shot for four.Next ball is free hit."<<endl;
        }

    else if(c=="n6")
    {
        x->runs+=7;
        x->extras+=1;
        x->individual_balls_played[*i]+=1;
        x->individual_runs[*i]+=6;
        if(x->individual_balls_played[*i]==0){
            x->individual_strike_rate[*i]=0;}
        else{
            x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
        x->sixes+=1;
        x->individual_sixes[*i]+=1;

        cout<<"It's no ball. That's huge for six.Next ball is free hit."<<endl;
        }

    else if(c=="n")
    {
        x->runs+=1;
        x->extras+=1;
        x->individual_balls_played[*i]+=1;
        if(x->individual_balls_played[*i]==0){
            x->individual_strike_rate[*i]=0;}
        else{
            x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}
        cout<<"It's no ball.Next ball is free hit."<<endl;
    }

    else if(c=="l1" || c=="l2" || c=="l3" || c=="l4")
    {
        x->individual_balls_played[*i]+=1;
        if(x->individual_balls_played[*i]==0){
            x->individual_strike_rate[*i]=0;}
        else{
            x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}

        if(c=="l1")
        {
            x->runs+=1;
            x->extras+=1;
            if(x->balls<5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"It's leg bye single."<<endl;
        }
        else if(c=="l2")
        {
            x->runs+=2;
            x->extras+=2;
            if(x->balls==5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"It's leg bye double."<<endl;
        }
        else if(c=="l3")
        {
            x->runs+=3;
            x->extras+=3;
            if(x->balls<5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"Good running for 3 leg bye runs."<<endl;
        }
        else if(c=="l4")
        {
            x->runs+=4;
            x->extras+=4;
            if(x->balls==5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"Lucky to get four on leg byes."<<endl;
        }

        if(x->balls==5)
        {
            x->overs+=1;
            x->balls=0;
            cout<<"End of the over."<<endl;
        }
        else
        {
            x->balls+=1;
        }
    }

    else if(c=="b1" || c=="b2" || c=="b3" || c=="b4")
    {
        x->individual_balls_played[*i]+=1;
        if(x->individual_balls_played[*i]==0){
            x->individual_strike_rate[*i]=0;}
        else{
            x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}

        if(c=="b1")
        {
            x->runs+=1;
            x->extras+=1;
            if(x->balls<5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"It's bye single."<<endl;
        }
        else if(c=="b2")
        {
            x->runs+=2;
            x->extras+=2;
            if(x->balls==5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"It's bye double."<<endl;
        }
        else if(c=="b3")
        {
            x->runs+=3;
            x->extras+=3;
            if(x->balls<5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"Good running for 3 bye runs."<<endl;
        }
        else if(c=="b4")
        {
            x->runs+=4;
            x->extras+=4;
            if(x->balls==5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }

            cout<<"Lucky to get four on byes."<<endl;
        }

        if(x->balls==5)
        {
            x->overs+=1;
            x->balls=0;
            cout<<"End of the over."<<endl;
        }
        else
        {
            x->balls+=1;
        }
    }

    else if(c=="shortrun")
    {
        x->runs+=1;
        x->individual_runs[*i]+=1;
        x->individual_balls_played[*i]+=1;
        if(x->individual_balls_played[*i]==0){
            x->individual_strike_rate[*i]=0;}
        else{
            x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}

        if(x->balls==5)
        {
            int temp=*i;
            *i=*j;
            *j=temp;
        }
        if(x->balls==5)
        {
            x->overs+=1;
            x->balls=0;
            cout<<"End of the over."<<endl;
        }
        else
        {
            x->balls+=1;
        }
    }

    else if(c=="bowled" || c=="stumped" || c=="catch"  || c=="lbw" || c=="widestumped" || c=="runout")
    {
        x->wickets+=1;
        x->individual_balls_played[*i]+=1;
        if(x->individual_balls_played[*i]==0){
            x->individual_strike_rate[*i]=0;}
        else{
            x->individual_strike_rate[*i]=(float(x->individual_runs[*i])/float(x->individual_balls_played[*i]))*100;}

        if(c=="bowled" || c=="stumped" || c=="catch")
        {
            cout<<"That's "<<c<<endl;

            if(x->wickets!=10){
            cin>>*i;
            cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;

            if(x->balls==5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }}
            if(x->balls==5)
            {
                x->overs+=1;
                x->balls=0;
                cout<<"End of the over."<<endl;
            }
            else
            {
                x->balls+=1;
            }
        }

        else if(c=="lbw")
        {
            cout<<"There's an appeal for the LBW and it's been given."<<endl;
            cout<<"There is "<<x->drs<<" remaining"<<endl;
            char choice;
            cin>>choice;
            cout<<endl;

            if(choice=='y' || 'Y')
            {
                cout<<"Batsman took the review."<<endl;
                cout<<endl;
                cout<<"Building up the DRS."<<endl;
                cout<<"Looking for the bat and ball contact."<<endl;
                char close;
                cin>>close;
                if(close=='y' || 'Y')
                {
                    cout<<"Ball is close to the bat."<<endl;
                    cout<<"Show the Ultra Edge."<<endl;
                    char ue;
                    cin>>ue;
                    if(ue=='y' || ue=='Y')
                    {
                        cout<<"There's some edge to the bat."<<endl;
                        cout<<"On-Field umpire please reverse your decision."<<endl;
                        x->wickets-=1;
                    }
                    else
                    {
                        cout<<"No bat involved on ultra edge."<<endl;
                        cout<<"Show ball tracking."<<endl;
                        cout<<endl;
                        char pitch;
                        char impact;
                        char hitting;
                        cin>>pitch;
                        if(pitch=='i' || pitch=='I')
                        {
                            cout<<"Pitching in line...";
                            cin>>impact;
                            if(impact=='i' || impact=='I')
                            {
                                cout<<"Impact in line...";
                                cin>>hitting;
                                if(hitting=='i' || hitting=='I')
                                {
                                    cout<<"Wickets hitting."<<endl;
                                    cout<<"Stay with the original decision of out."<<endl;
                                    x->drs--;
                                    if(x->wickets!=10){
                                        cin>>*i;
                                        cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                    }
                                }
                                else if(hitting=='u' || hitting=='U')
                                {
                                    cout<<"hitting is umpire's call."<<endl;
                                    cout<<"Stay with the original decision of out."<<endl;
                                    if(x->wickets!=10){
                                        cin>>*i;
                                        cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"wickets missing."<<endl;
                                    cout<<"On-Field umpire please reverse your decision."<<endl;
                                    x->wickets-=1;

                                }
                            }
                            else if(impact=='u' || impact=='U')
                            {
                                cout<<"Impact is umpire's cal...";
                                cin>>hitting;
                                if(hitting=='i' || hitting=='I')
                                {
                                    cout<<"Wickets hitting."<<endl;
                                    cout<<"Stay with the original decision of out."<<endl;
                                    if(x->wickets!=10){
                                        cin>>*i;
                                        cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                    }
                                }
                                else if(hitting=='u' || hitting=='U')
                                {
                                    cout<<"hitting is umpire's call."<<endl;
                                    cout<<"Stay with the original decision of out."<<endl;
                                    if(x->wickets!=10){
                                        cin>>*i;
                                        cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"wickets missing."<<endl;
                                    cout<<"On-Field umpire please reverse your decision."<<endl;
                                    x->wickets-=1;
                                }
                            }
                            else
                            {
                                cout<<"Impact is outside the stump line."<<endl;
                                cout<<"On-Field umpire please reverse your decision."<<endl;
                                x->wickets-=1;
                            }
                        }
                        else if(pitch=='u' || pitch=='U')
                        {
                            cout<<"Pitching is umpire's call...";
                            cin>>impact;
                            if(impact=='i' || impact=='I')
                            {
                                cout<<"Impact in line...";
                                cin>>hitting;
                                if(hitting=='i' || hitting=='I')
                                {
                                    cout<<"Wickets hitting."<<endl;
                                    cout<<"Stay with the original decision of out."<<endl;
                                    if(x->wickets!=10){
                                        cin>>*i;
                                        cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                    }
                                }
                                else if(hitting=='u' || hitting=='U')
                                {
                                    cout<<"hitting is umpire's call."<<endl;
                                    cout<<"Stay with the original decision of out."<<endl;
                                    if(x->wickets!=10){
                                        cin>>*i;
                                        cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"wickets missing."<<endl;
                                    cout<<"On-Field umpire please reverse your decision."<<endl;
                                    x->wickets-=1;

                                }
                            }
                            else if(impact=='u' || impact=='U')
                            {
                                cout<<"Impact is umpire's cal...";
                                cin>>hitting;
                                if(hitting=='i' || hitting=='I')
                                {
                                    cout<<"Wickets hitting."<<endl;
                                    cout<<"Stay with the original decision of out."<<endl;
                                    if(x->wickets!=10){
                                        cin>>*i;
                                        cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                    }
                                }
                                else if(hitting=='u' || hitting=='U')
                                {
                                    cout<<"hitting is umpire's call."<<endl;
                                    cout<<"Stay with the original decision of out."<<endl;
                                    if(x->wickets!=10){
                                        cin>>*i;
                                        cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                    }
                                }
                                else
                                {
                                    cout<<"wickets missing."<<endl;
                                    cout<<"On-Field umpire please reverse your decision."<<endl;
                                    x->wickets-=1;
                                }
                            }
                            else
                            {
                                cout<<"Impact is outside the stump line."<<endl;
                                cout<<"On-Field umpire please reverse your decision."<<endl;
                                x->wickets-=1;
                            }
                        }
                        else
                        {
                            cout<<"Pitching is outside the stumps line."<<endl;
                            cout<<"On-Field umpire please reverse your decision."<<endl;
                            x->wickets-=1;
                        }
                    }
                }
                else
                {
                    cout<<"Bat is nowhere."<<endl;
                    cout<<"Show ball tracking directly."<<endl;
                    char pitch;
                    char impact;
                    char hitting;
                    cin>>pitch;
                    if(pitch=='i' || pitch=='I')
                    {
                        cout<<"Pitching in line...";
                        cin>>impact;
                        if(impact=='i' || impact=='I')
                        {
                            cout<<"Impact in line...";
                            cin>>hitting;
                            if(hitting=='i' || hitting=='I')
                            {
                                cout<<"Wickets hitting."<<endl;
                                cout<<"Stay with the original decision of out."<<endl;
                                x->drs--;
                                if(x->wickets!=10){
                                    cin>>*i;
                                    cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                }
                            }
                            else if(hitting=='u' || hitting=='U')
                            {
                                cout<<"hitting is umpire's call."<<endl;
                                cout<<"Stay with the original decision of out."<<endl;
                                if(x->wickets!=10){
                                    cin>>*i;
                                    cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                }
                            }
                            else
                            {
                                cout<<"wickets missing."<<endl;
                                cout<<"On-Field umpire please reverse your decision."<<endl;
                                x->wickets-=1;

                            }
                        }
                        else if(impact=='u' || impact=='U')
                        {
                            cout<<"Impact is umpire's cal...";
                            cin>>hitting;
                            if(hitting=='i' || hitting=='I')
                            {
                                cout<<"Wickets hitting."<<endl;
                                cout<<"Stay with the original decision of out."<<endl;
                                if(x->wickets!=10){
                                    cin>>*i;
                                    cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                }
                            }
                            else if(hitting=='u' || hitting=='U')
                            {
                                cout<<"hitting is umpire's call."<<endl;
                                cout<<"Stay with the original decision of out."<<endl;
                                if(x->wickets!=10){
                                    cin>>*i;
                                    cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                }
                            }
                            else
                            {
                                cout<<"wickets missing."<<endl;
                                cout<<"On-Field umpire please reverse your decision."<<endl;
                                x->wickets-=1;
                            }
                        }
                        else
                        {
                            cout<<"Impact is outside the stump line."<<endl;
                            cout<<"On-Field umpire please reverse your decision."<<endl;
                            x->wickets-=1;
                        }
                    }
                    else if(pitch=='u' || pitch=='U')
                    {
                        cout<<"Pitching is umpire's call...";
                        cin>>impact;
                        if(impact=='i' || impact=='I')
                        {
                            cout<<"Impact in line...";
                            cin>>hitting;
                            if(hitting=='i' || hitting=='I')
                            {
                                cout<<"Wickets hitting."<<endl;
                                cout<<"Stay with the original decision of out."<<endl;
                                if(x->wickets!=10){
                                    cin>>*i;
                                    cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                }
                            }
                            else if(hitting=='u' || hitting=='U')
                            {
                                cout<<"hitting is umpire's call."<<endl;
                                cout<<"Stay with the original decision of out."<<endl;
                                if(x->wickets!=10){
                                    cin>>*i;
                                    cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                }
                            }
                            else
                            {
                                cout<<"wickets missing."<<endl;
                                cout<<"On-Field umpire please reverse your decision."<<endl;
                                x->wickets-=1;

                            }
                        }
                        else if(impact=='u' || impact=='U')
                        {
                            cout<<"Impact is umpire's cal...";
                            cin>>hitting;
                            if(hitting=='i' || hitting=='I')
                            {
                                cout<<"Wickets hitting."<<endl;
                                cout<<"Stay with the original decision of out."<<endl;
                                if(x->wickets!=10){
                                    cin>>*i;
                                    cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                }
                            }
                            else if(hitting=='u' || hitting=='U')
                            {
                                cout<<"hitting is umpire's call."<<endl;
                                cout<<"Stay with the original decision of out."<<endl;
                                if(x->wickets!=10){
                                    cin>>*i;
                                    cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;
                                }
                            }
                            else
                            {
                                cout<<"wickets missing."<<endl;
                                cout<<"On-Field umpire please reverse your decision."<<endl;
                                x->wickets-=1;
                            }
                        }
                        else
                        {
                            cout<<"Impact is outside the stump line."<<endl;
                            cout<<"On-Field umpire please reverse your decision."<<endl;
                            x->wickets-=1;
                        }
                    }
                    else
                    {
                        cout<<"Pitching is outside the stumps line."<<endl;
                        cout<<"On-Field umpire please reverse your decision."<<endl;
                        x->wickets-=1;
                    }
                }
            }

            if(x->balls==5)
            {
                int temp=*i;
                *i=*j;
                *j=temp;
            }
            if(x->balls==5)
            {
                x->overs+=1;
                x->balls=0;
                cout<<"End of the over."<<endl;
            }
            else
            {
                x->balls+=1;
            }
        }

        else if(c=="widestumped")
        {
            x->balls-=1;
            x->individual_balls_played[*i]-=1;
            x->extras+=1;
            x->runs+=1;
            cout<<"That's wide and stumped!"<<endl;

            if(x->wickets!=10){
            cin>>*i;
            cout<<"Next batsman "<<x->team_starting_11_name[*i]<<" comes in to bat."<<endl;}
        }

        else if(c=="runout")
        {
            int r;
            cin>>r;
            x->runs+=r;
            x->individual_runs[*i]+=r;
            int y;//player who is out. 1 if i is out and 2 if j is out.
            cin>>y;
            int z;//end at which run out is done. 1 if striker end and 2 if non-striker end.
            cin>>z;

            if(y==1)
            {
                cin>>*i;
            }
            else
            {
                cin>>*j;
            }

            if((y==1 && z==1) || (y==2 && z==2))
            {
                if(x->balls==5)
                {
                    int temp=*i;
                    *i=*j;
                    *j=temp;
                }
            }
            else
            {
                if(x->balls<5)
                {
                    int temp=*i;
                    *i=*j;
                    *j=temp;
                }
            }

            cout<<"Lack of understanding between two players and it's a run out."<<endl;

            if(x->balls==5)
            {
                x->overs+=1;
                x->balls=0;
                cout<<"End of the over."<<endl;
            }
            else
            {
                x->balls+=1;
            }
        }
    }
    float a=x->overs*6+x->balls;
    float rpo=x->runs/(a/6);
    x->run_rate=rpo;

    cout<<x->runs<<"-"<<x->wickets<<" in "<<x->overs<<"."<<x->balls<<" at "<<x->run_rate<<" rpo."<<endl;
    cout<<x->team_starting_11_name[*i]<<" will face the next ball."<<endl;
    cout<<endl;
}

int main()
{
    string first_team;
    string second_team;

    struct team team1;
    struct team team2;

    cout<<"Enter first team name: "<<endl;
    getline(cin,first_team);
    InputTeamName(&team1,first_team);
    cout<<"Enter all players in its squad"<<endl;
    InputAllPlayers(&team1);

    cout<<"Enter second team name: "<<endl;
    getline(cin,second_team);
    InputTeamName(&team2,second_team);
    cout<<"Enter all players in its squad"<<endl;
    InputAllPlayers(&team2);

    cout<<endl;

    cout<<"Welcome to "<<first_team<<" vs "<<second_team<<" T20 match.\n"<<endl;

    cout<<"The squads are as follows: \n"<<endl;
    cout<<first_team<<endl;
    DisplayAllPlayers(&team1);
    cout<<endl;
    cout<<second_team<<endl;
    DisplayAllPlayers(&team2);
    cout<<endl;

    cout<<"It is now time for the toss."<<second_team<<" will take the call."<<endl;
    string toss_call;
    cin>>toss_call;
    cout<<toss_call<<" is the call..."<<endl;

    string toss_outcome;
    cin>>toss_outcome;
    cout<<"...And it's "<<toss_outcome<<endl;
    cout<<endl;

    if(toss_call==toss_outcome)
    {
        cout<<second_team<<" won the toss. What would you like to do?"<<endl;
        string choice;
        cin>>choice;
        cout<<"We would like to do "<<choice<<" first."<<endl;
        cout<<endl;
        if(choice=="batting")
        {
            cout<<second_team<<" choose your starting 11."<<endl;
            InputStarting11(&team2);
            cout<<first_team<<" choose your starting 11."<<endl;
            InputStarting11(&team1);
            cout<<endl;

            cout<<second_team<<endl;
            DisplayStarting11(&team2);
            cout<<endl;
            cout<<first_team<<endl;
            DisplayStarting11(&team1);
            cout<<endl;

            cout<<"So "<<second_team<<" won the toss and elected to "<<choice<<" first. Match will begin shortly."<<endl;
            cout<<endl;
            cout<<"The match begins."<<endl;
            InitializeData(&team2);
            int i=0,j=1;
            cout<<team2.team_starting_11_name[i]<<" and "<<team2.team_starting_11_name[j]<<" comes in as openers."<<endl;

            while(team2.wickets!=10 && team2.overs!=20)
            {
                string c;
                cin>>c;
                UpdateBattingScorecard(c,&team2,&i,&j);
            }
            DisplayBattingScorecard(&team2);
            cout<<"So the first inning is over. We will be right back in few minutes."<<endl;

            cout<<"Second innings started..."<<endl;
            InitializeData(&team1);
            i=0,j=1;
            cout<<team1.team_starting_11_name[i]<<" and "<<team1.team_starting_11_name[j]<<" comes in as openers."<<endl;

            while(team1.wickets!=10 && team1.overs!=20)
            {
                string c;
                cin>>c;
                UpdateBattingScorecard(c,&team1,&i,&j);
            }
            DisplayBattingScorecard(&team1);
        }

        else
        {
            cout<<first_team<<" choose your starting 11."<<endl;
            InputStarting11(&team1);
            cout<<second_team<<" choose your starting 11."<<endl;
            InputStarting11(&team2);
            cout<<endl;

            cout<<first_team<<endl;
            DisplayStarting11(&team1);
            cout<<endl;
            cout<<second_team<<endl;
            DisplayStarting11(&team2);
            cout<<endl;
            cout<<"So "<<second_team<<" won the toss and elected to "<<choice<<" first. Match will begin shortly."<<endl;
            cout<<endl;
            cout<<"The match begins."<<endl;
            InitializeData(&team1);
            int i=0,j=1;
            cout<<team1.team_starting_11_name[i]<<" and "<<team1.team_starting_11_name[j]<<" comes in as openers."<<endl;

            while(team1.wickets!=10 && team1.overs!=20)
            {
                string c;
                cin>>c;
                UpdateBattingScorecard(c,&team1,&i,&j);
            }
            DisplayBattingScorecard(&team1);
            cout<<"So the first inning is over. We will be right back in few minutes."<<endl;

            cout<<"Second innings started..."<<endl;
            InitializeData(&team2);
            i=0,j=1;
            cout<<team2.team_starting_11_name[i]<<" and "<<team2.team_starting_11_name[j]<<" comes in as openers."<<endl;

            while(team2.wickets!=10 && team2.overs!=20)
            {
                string c;
                cin>>c;
                UpdateBattingScorecard(c,&team2,&i,&j);
            }
            DisplayBattingScorecard(&team2);
        }

        if(team1.runs==team2.runs)
        {
            cout<<"The match is drawn.";
        }
        else if(team1.runs>team2.runs)
        {
            cout<<team1.name<<" won the match."<<endl;
        }
        else
        {
            cout<<team2.name<<" won the match."<<endl;
        }
    }

    else
    {
        cout<<first_team<<" won the toss. What would you like to do."<<endl;
        string choice;
        cin>>choice;
        cout<<"We would like to "<<choice<<" first."<<endl;
        if(choice=="batting")
        {
            cout<<first_team<<" choose your starting 11."<<endl;
            InputStarting11(&team1);
            cout<<second_team<<" choose your starting 11."<<endl;
            InputStarting11(&team2);
            cout<<endl;

            cout<<first_team<<endl;
            DisplayStarting11(&team1);
            cout<<endl;
            cout<<second_team<<endl;
            DisplayStarting11(&team2);
            cout<<endl;
            cout<<"So "<<second_team<<" won the toss and elected to "<<choice<<" first. Match will begin shortly."<<endl;
            cout<<endl;
            cout<<"The match begins."<<endl;
            InitializeData(&team1);
            int i=0,j=1;
            cout<<team1.team_starting_11_name[i]<<" and "<<team1.team_starting_11_name[j]<<" comes in as openers."<<endl;

            while(team1.wickets!=10 && team1.overs!=20)
            {
                string c;
                cin>>c;
                UpdateBattingScorecard(c,&team1,&i,&j);
            }
            DisplayBattingScorecard(&team1);
            cout<<"So the first inning is over. We will be right back in few minutes."<<endl;

            cout<<"Second innings started..."<<endl;
            InitializeData(&team2);
            i=0,j=1;
            cout<<team2.team_starting_11_name[i]<<" and "<<team2.team_starting_11_name[j]<<" comes in as openers."<<endl;

            while(team2.wickets!=10 && team2.overs!=20)
            {
                string c;
                cin>>c;
                UpdateBattingScorecard(c,&team2,&i,&j);
            }
            DisplayBattingScorecard(&team2);
        }
        else
        {
            cout<<second_team<<" choose your starting 11."<<endl;
            InputStarting11(&team2);
            cout<<first_team<<" choose your starting 11."<<endl;
            InputStarting11(&team1);
            cout<<endl;

            cout<<second_team<<endl;
            DisplayStarting11(&team2);
            cout<<endl;
            cout<<first_team<<endl;
            DisplayStarting11(&team1);
            cout<<endl;
            cout<<"So "<<second_team<<" won the toss and elected to "<<choice<<" first. Match will begin shortly."<<endl;
            cout<<endl;
            cout<<"The match begins."<<endl;
            InitializeData(&team2);
            int i=0,j=1;
            cout<<team2.team_starting_11_name[i]<<" and "<<team2.team_starting_11_name[j]<<" comes in as openers."<<endl;

            while(team2.wickets!=10 && team2.overs!=20)
            {
                string c;
                cin>>c;
                UpdateBattingScorecard(c,&team2,&i,&j);
            }
            DisplayBattingScorecard(&team2);
            cout<<"So the first inning is over. We will be right back in few minutes."<<endl;

            cout<<"Second innings started..."<<endl;
            InitializeData(&team1);
            i=0,j=1;
            cout<<team1.team_starting_11_name[i]<<" and "<<team1.team_starting_11_name[j]<<" comes in as openers."<<endl;

            while(team1.wickets!=10 && team1.overs!=20)
            {
                string c;
                cin>>c;
                UpdateBattingScorecard(c,&team1,&i,&j);
            }
            DisplayBattingScorecard(&team1);
        }

        if(team1.runs==team2.runs)
        {
            cout<<"The match is drawn.";
        }
        else if(team1.runs>team2.runs)
        {
            cout<<team1.name<<" won the match."<<endl;
        }
        else
        {
            cout<<team2.name<<" won the match."<<endl;
        }
    }
    return 0;
}
