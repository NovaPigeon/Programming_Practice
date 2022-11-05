//
//  main.cpp
//  魔兽世界三：开战(参考答案)
//
//  Created by 寿晨宸 on 2022/3/28.
//

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

class Warrior;

int Loyalty_Decrease,City_Amount;
int Cost[5],Power[5],Time_Index;
int ord1[5]={2,3,4,1,0},ord2[5]={3,0,1,2,4};
Warrior* City[22][2];//0->red & 1->blue;
Warrior* New_City[22][2];
char Weapon_Name[3][6]={"sword","bomb","arrow"};
char Warrior_Name[5][7]={"dragon","ninja","iceman","lion","wolf"};
char Headquarter_Name[2][5]={"red","blue"};
bool Red_Lost,Blue_Lost;

inline int MAX(int a,int b){return a>b?a:b;}

class Weapon{
public:
    int Can_use;
    int Index;
    char Name[6];
    Weapon(char* s,int I_){
        strcpy(Name,s);
        Index=I_;
        Can_use=2;
    }
    int Use(){return Can_use;}
    virtual void AD(Warrior *Owner,Warrior *Enermy);
};

bool cmp(const Weapon *A,const Weapon *B){
    if(A==NULL) return false;
    if(B==NULL) return true;
    if(A->Index!=B->Index) return A->Index<B->Index;
    return A->Can_use>B->Can_use;
}

class Sword: public Weapon{
public:
    Sword():Weapon(Weapon_Name[0],0){};
    virtual void AD(Warrior *Owner,Warrior *Enermy);
};
class Bomb: public Weapon{
public:
    Bomb():Weapon(Weapon_Name[1],1){};
    virtual void AD(Warrior *Owner,Warrior *Enermy);
};

class Arrow: public Weapon{
public:
    Arrow():Weapon(Weapon_Name[2],2){};
    virtual void AD(Warrior *Owner,Warrior *Enermy);
};

class Warrior{
public:
    int HP,MP;
    int City_Index,Direction;
    char Name[7];
    int Born_Number;
    int Weapon_Count;
    int Weapon_Index;
    bool Die;
    Weapon* w[10];
    Warrior(int HP_,int MP_,char *s,int B_,int C_,int D_){
        memset(Name,0,sizeof(Name));
        memset(w,0,sizeof(w));
        Weapon_Count=0;
        HP=HP_;
        MP=MP_;
        strcpy(Name,s);
        City_Index=C_;
        Direction=D_;
        Die=false;
        Born_Number=B_;
    }
    virtual void get_weapon(){
        switch((Time_Index+1)%3){
            case 0: w[Weapon_Count++]=new Sword;break;
            case 1: w[Weapon_Count++]=new Bomb;break;
            case 2: w[Weapon_Count++]=new Arrow;break;
        };
    }
    virtual void After_Born(){}
    void Hurt(int Damage){
        HP-=Damage;
        if(HP<=0) Die=true;
    }
    virtual bool Escape(){return false;}
    virtual bool Is_Wolf(){return false;}
    virtual bool Is_Ninja(){return false;}
    virtual void Before_fight(Warrior *Enermy){}
    void Use_Weapon(Warrior *Enermy){
        if(!Weapon_Count) return ;
        int temp=0;
        while(w[Weapon_Index=(Weapon_Index+1)%10]==NULL && temp<10) temp++;
        w[Weapon_Index]->AD(this,Enermy);
        if(!w[Weapon_Index]->Use()){
            delete w[Weapon_Index],w[Weapon_Index]=NULL;
            Weapon_Count--;
        }
        if(Enermy->Die && !Die){
            //in order to make the Weapon is in the w[Weapon_Count]'s place You have to reorder it before get others
            sort(w,w+10,cmp);
            if(Weapon_Count<10 && Enermy->Weapon_Count>0){
                sort(Enermy->w,Enermy->w+Enermy->Weapon_Count,cmp);
                for(int i=0;i<Enermy->Weapon_Count && Weapon_Count<10;i++)
                    w[Weapon_Count++]=Enermy->w[i];
            }
        }
        if(!Enermy->Die && Die){
            sort(Enermy->w,Enermy->w+10,cmp);
            if(Enermy->Weapon_Count<10 && Weapon_Count>0){
                sort(w,w+Weapon_Count,cmp);
                for(int i=0;i<Weapon_Count && Enermy->Weapon_Count<10;i++)
                    Enermy->w[Weapon_Count++]=w[i];
            }
        }
    }
    /*Time_Tick is a clock to test the max time that both are still*/
    void Fight_First(Warrior *A){
        if(Weapon_Count) sort(w,w+10,cmp);
        if(A->Weapon_Count) sort(A->w,A->w+10,cmp);
        Weapon_Index=-1;
        A->Weapon_Index=-1;
        int rec_HP=HP,rec_HP_A=A->HP,rec_W=Weapon_Count,rec_W_A=A->Weapon_Count;
        int Time_Tick=2*MAX(rec_W,rec_W_A);
        while(!Die && !A->Die && (Weapon_Count || A->Weapon_Count) ){
            Use_Weapon(A);
            if(!A->Die)
                A->Use_Weapon(this);
            if(--Time_Tick==0){
                if(rec_HP==HP && rec_HP_A==A->HP && rec_W==Weapon_Count && rec_W_A==A->Weapon_Count)
                    break;
                else{
                    rec_HP=HP,rec_HP_A=A->HP,rec_W=Weapon_Count,rec_W_A=A->Weapon_Count;
                    Time_Tick=MAX(rec_W,rec_W_A);
                }
            }
        }
        Warrior *r;
        Warrior *b;
        if(Direction>0) r=this,b=A;
        else r=A,b=this;
        if(r->Die){
            if(b->Die) printf("%03d:40 both red %s %d and blue %s %d died in city %d\n",Time_Index,r->Name,r->Born_Number,b->Name,b->Born_Number,r->City_Index);
            else printf("%03d:40 blue %s %d killed red %s %d in city %d remaining %d elements\n",Time_Index,b->Name,b->Born_Number,r->Name,r->Born_Number,r->City_Index,b->HP);
        }
        else{
            if(b->Die) printf("%03d:40 red %s %d killed blue %s %d in city %d remaining %d elements\n",Time_Index,r->Name,r->Born_Number,b->Name,b->Born_Number,r->City_Index,r->HP);
            else printf("%03d:40 both red %s %d and blue %s %d were alive in city %d\n",Time_Index,r->Name,r->Born_Number,b->Name,b->Born_Number,r->City_Index);
        }
    }
    virtual void Process(){
        City[City_Index][Direction<0]=NULL;
        City_Index+=Direction;
        New_City[City_Index][Direction<0]=this;
        if(City_Index==0){
            Red_Lost=true;
            printf("%03d:10 blue %s %d reached red headquarter with %d elements and force %d\n",Time_Index,Name,Born_Number,HP,MP);
            printf("%03d:10 red headquarter was taken\n",Time_Index);
        }
        else if(City_Index==City_Amount+1){
            Blue_Lost=true;
            printf("%03d:10 red %s %d reached blue headquarter with %d elements and force %d\n",Time_Index,Name,Born_Number,HP,MP);
            printf("%03d:10 blue headquarter was taken\n",Time_Index);
        }
        else
            printf("%03d:10 %s %s %d marched to city %d with %d elements and force %d\n",Time_Index,Headquarter_Name[Direction<0],Name,Born_Number,City_Index,HP,MP);
    }
    void Print_Weapon(){
        int cnt[3];
        for(int i=0;i<3;i++) cnt[i]=0;
        for(int i=0;i<10;i++)
            if(w[i]!=NULL) cnt[w[i]->Index]++;
        printf("%03d:55 %s %s %d has %d sword %d bomb %d arrow and %d elements\n",Time_Index,Headquarter_Name[Direction<0],Name,Born_Number,cnt[0],cnt[1],cnt[2],HP);
    }
    virtual void After_Fight(Warrior* Enermy){}
};
//0
class Dragon:public Warrior{
public:
    Dragon(int HP,int MP_,int B_,int C_,int D_):Warrior(HP,MP_,Warrior_Name[0],B_,C_,D_){}
    virtual void After_Fight(Warrior* Enermy){
        printf("%03d:40 %s dragon %d yelled in city %d\n",Time_Index,Headquarter_Name[Direction<0],Born_Number,City_Index);
    }
};
//1
class Ninja:public Warrior{
public:
    Ninja(int HP,int MP_,int B_,int C_,int D_):Warrior(HP,MP_,Warrior_Name[1],B_,C_,D_){}
    virtual void get_weapon(){
        switch((Time_Index+1)%3){
            case 0: w[Weapon_Count++]=new Sword;break;
            case 1: w[Weapon_Count++]=new Bomb;break;
            case 2: w[Weapon_Count++]=new Arrow;break;
        };
        switch((Time_Index+2)%3){
            case 0: w[Weapon_Count++]=new Sword;break;
            case 1: w[Weapon_Count++]=new Bomb;break;
            case 2: w[Weapon_Count++]=new Arrow;break;
        };
    }
    virtual bool Is_Ninja(){return true;}
};
//2
class Iceman:public Warrior{
public:
    Iceman(int HP,int MP_,int B_,int C_,int D_):Warrior(HP,MP_,Warrior_Name[2],B_,C_,D_){}
    virtual void Process(){
        City[City_Index][Direction<0]=NULL;
        City_Index+=Direction;
        New_City[City_Index][Direction<0]=this;
        HP-=HP/10;
        if(City_Index==0){
            Red_Lost=true;
            printf("%03d:10 blue %s %d reached red headquarter with %d elements and force %d\n",Time_Index,Name,Born_Number,HP,MP);
            printf("%03d:10 red headquarter was taken\n",Time_Index);
        }
        else if(City_Index==City_Amount+1){
            Blue_Lost=true;
            printf("%03d:10 red %s %d reached blue headquarter with %d elements and force %d\n",Time_Index,Name,Born_Number,HP,MP);
            printf("%03d:10 blue headquarter was taken\n",Time_Index);
        }
        else
            printf("%03d:10 %s %s %d marched to city %d with %d elements and force %d\n",Time_Index,Headquarter_Name[Direction<0],Name,Born_Number,City_Index,HP,MP);
    }
};
//3
class Lion:public Warrior{
    int loyalty;
public:
    Lion(int HP,int MP_,int l_,int B_,int C_,int D_):Warrior(HP,MP_,Warrior_Name[3],B_,C_,D_){loyalty=l_;}
    virtual void After_Born(){
        printf("Its loyalty is %d\n",loyalty);
    }
    virtual bool Escape(){return loyalty<=0;}
    virtual void Process(){
        City[City_Index][Direction<0]=NULL;
        City_Index+=Direction;
        New_City[City_Index][Direction<0]=this;
        loyalty-=Loyalty_Decrease;
        if(City_Index==0){
            Red_Lost=true;
            printf("%03d:10 blue %s %d reached red headquarter with %d elements and force %d\n",Time_Index,Name,Born_Number,HP,MP);
            printf("%03d:10 red headquarter was taken\n",Time_Index);
        }
        else if(City_Index==City_Amount+1){
            Blue_Lost=true;
            printf("%03d:10 red %s %d reached blue headquarter with %d elements and force %d\n",Time_Index,Name,Born_Number,HP,MP);
            printf("%03d:10 blue headquarter was taken\n",Time_Index);
        }
        else
            printf("%03d:10 %s %s %d marched to city %d with %d elements and force %d\n",Time_Index,Headquarter_Name[Direction<0],Name,Born_Number,City_Index,HP,MP);
    }
};
//4
class Wolf:public Warrior{
public:
    Wolf(int HP,int MP_,int B_,int C_,int D_):Warrior(HP,MP_,Warrior_Name[4],B_,C_,D_){}
    virtual void get_weapon(){}
    virtual void Weapon_print(){}
    virtual bool Is_Wolf(){return true;}
    virtual void Before_fight(Warrior *Enermy){
        if(Enermy->Is_Wolf()) return;
        if(Weapon_Count<10 && Enermy->Weapon_Count>0){
            sort(w,w+10,cmp);
            sort(Enermy->w,Enermy->w+10,cmp);
            int Min_Index=Enermy->w[0]->Index,Amount=0;
            for(int i=0;Enermy->w[i]!=NULL && Enermy->w[i]->Index==Min_Index && Weapon_Count<10 && i<Enermy->Weapon_Count+Amount;i++){
                w[Weapon_Count++]=Enermy->w[i],Amount++;
                Enermy->Weapon_Count--;
                Enermy->w[i]=NULL;
            }
            printf("%03d:35 %s wolf %d took %d %s from %s %s %d in city %d\n",Time_Index,Headquarter_Name[Direction<0],Born_Number,Amount,Weapon_Name[Min_Index],Headquarter_Name[Direction>0],Enermy->Name,Enermy->Born_Number,City_Index);
        }
    }
};

void Weapon::AD(Warrior *Owner,Warrior *Enermy){}
void Sword::AD(Warrior*Owner,Warrior *Enermy){ Enermy->Hurt(Owner->MP/5);}
void Bomb::AD(Warrior*Owner,Warrior *Enermy){
    Owner->w[Owner->Weapon_Index]->Can_use-=2;
    Enermy->Hurt(Owner->MP*2/5);
    if(!Owner->Is_Ninja())
        Owner->Hurt(Owner->MP*2/5/2);
}
void Arrow::AD(Warrior*Owner,Warrior *Enermy){
    Owner->w[Owner->Weapon_Index]->Can_use--;
    Enermy->Hurt(Owner->MP*3/10);
}

class Headquarter{
private:
    char Name[5];
    int HP;
    int Order[5];
    int Count[5];
    int Warrior_Index;
    Warrior *cur;
    bool STOP;
public:
    Headquarter(char *s,int HP_,int* O_){
        memset(Name,0,sizeof(Name));
        memset(Count,0,sizeof(Count));
        strcpy(Name,s);
        HP=HP_;
        for(int i=0;i<5;i++)
            Order[i]=O_[i];
        Warrior_Index=-1;
        cur=NULL;
        STOP=0;
    }
    void Change_HP(int HP_){
        HP=HP_;
        memset(Count,0,sizeof(Count));
        Warrior_Index=-1;
        cur=NULL;
        STOP=0;
    };
    void Build_Warrior(){
        if(STOP) return;
        int Born_Place,Direct;
        if(Name[0]=='r') Born_Place=0,Direct=1;
        else Born_Place=City_Amount+1,Direct=-1;
        Warrior_Index=(Warrior_Index+1)%5;
        int who=Order[Warrior_Index];
        if(HP>=Cost[who]){
            Count[who]++;
            HP-=Cost[who];
            switch(who){
                case 0: cur=new Dragon(Cost[0],Power[0],Time_Index+1,Born_Place,Direct);break;
                case 1: cur=new Ninja(Cost[1],Power[1],Time_Index+1,Born_Place,Direct);break;
                case 2: cur=new Iceman(Cost[2],Power[2],Time_Index+1,Born_Place,Direct);break;
                case 3: cur=new Lion(Cost[3],Power[3],HP,Time_Index+1,Born_Place,Direct);break;
                case 4: cur=new Wolf(Cost[4],Power[4],Time_Index+1,Born_Place,Direct);break;
            };
            cur->get_weapon();
            printf("%03d:00 %s %s %d born\n",Time_Index,Name,Warrior_Name[who],Time_Index+1);
            cur->After_Born();
            if(Name[0]=='r') City[0][0]=cur;
            else City[City_Amount+1][1]=cur;
            cur=NULL;
        }
        else{
            //printf("%03d:00 %s headquarter stops making warriors\n",Time_Index,Name);
            STOP=true;
        }
    }
    void Print_HP(){
        printf("%03d:50 %d elements in %s headquarter\n",Time_Index,HP,Name);
    }
    bool Stop(){return STOP;}
};

Headquarter r(Headquarter_Name[0],0,ord1),b(Headquarter_Name[1],0,ord2);

int main(){
/*#ifndef ONLINE_JUDGE
    freopen("x.in","r",stdin);
    freopen("x.out","w",stdout);
#endif*/
    int Kase,W,Time,Time_Sum;
    scanf("%d",&Kase);
    for(int T=1;T<=Kase;T++){
        printf("Case %d:\n",T);
        scanf("%d%d%d%d",&W,&City_Amount,&Loyalty_Decrease,&Time);
        for(int j=0;j<=City_Amount+1;j++)City[j][0]=City[j][1]=NULL;
        Time_Index=Time_Sum=0;
        r.Change_HP(W); b.Change_HP(W);
        Red_Lost=Blue_Lost=false;
        for(int i=0;i<5;i++)
            scanf("%d",&Cost[i]);
        for(int i=0;i<5;i++)
            scanf("%d",&Power[i]);
        while(Time_Sum<=Time){
            //Time:0
            r.Build_Warrior();
            b.Build_Warrior();
            //Time:5
            if(Time<Time_Sum+5) break;
            for(int i=0;i<=City_Amount+1;i++){
                if(City[i][0]!=NULL && City[i][0]->Escape()){
                    printf("%03d:05 red lion %d ran away\n",Time_Index,City[i][0]->Born_Number);
                    delete City[i][0],City[i][0]=NULL;
                }
                if(City[i][1]!=NULL && City[i][1]->Escape()){
                    printf("%03d:05 blue lion %d ran away\n",Time_Index,City[i][1]->Born_Number);
                    delete City[i][1],City[i][1]=NULL;
                }
            }
            //Time:10
            if(Time<Time_Sum+10) break;
            for(int i=0;i<=City_Amount+1;i++){
                if(i>0)
                    if(City[i-1][0]!=NULL) City[i-1][0]->Process();
                if(i<=City_Amount)
                    if(City[i+1][1]!=NULL) City[i+1][1]->Process();
            }
            if(Blue_Lost || Red_Lost) break;
            for(int i=0;i<=City_Amount+1;i++){
                City[i][0]=New_City[i][0];
                New_City[i][0]=NULL;
                City[i][1]=New_City[i][1];
                New_City[i][1]=NULL;
            }
            //Time:35
            if(Time<Time_Sum+35) break;
            for(int i=1;i<=City_Amount;i++){
                if(City[i][0]!=NULL && City[i][1]!=NULL){
                    City[i][0]->Before_fight(City[i][1]);
                    City[i][1]->Before_fight(City[i][0]);
                }
            }
            //Time:40
            if(Time<Time_Sum+40) break;
            for(int i=1;i<=City_Amount;i++){
                if(City[i][0]!=NULL && City[i][1]!=NULL){
                    City[i][!(i&1)]->Fight_First(City[i][i&1]);
                    if(!City[i][0]->Die) City[i][0]->After_Fight(City[i][1]);
                    if(!City[i][1]->Die) City[i][1]->After_Fight(City[i][0]);
                    if(City[i][0]->Die) delete City[i][0],City[i][0]=NULL;
                    if(City[i][1]->Die) delete City[i][1],City[i][1]=NULL;
                }
            }
            //Time:50
            if(Time<Time_Sum+50) break;
            r.Print_HP();
            b.Print_HP();
            //Time:55
            if(Time<Time_Sum+55) break;
            for(int i=0;i<=City_Amount+1;i++){
                if(City[i][0]!=NULL) City[i][0]->Print_Weapon();
                if(City[i][1]!=NULL) City[i][1]->Print_Weapon();
            }
            Time_Index++;
            Time_Sum+=60;
        }
        //Delete all the warriors alive
        for(int j=0;j<=City_Amount+1;j++){
            if(City[j][0]!=NULL) delete City[j][0],City[j][0]=NULL;
            if(City[j][1]!=NULL) delete City[j][1],City[j][1]=NULL;
            if(New_City[j][0]!=NULL) delete New_City[j][0],New_City[j][0]=NULL;
            if(New_City[j][1]!=NULL) delete New_City[j][1],New_City[j][1]=NULL;
        }
    }
    return 0;
}
