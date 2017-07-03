#include<iostream>
#include<stdlib.h>
#include<vector>
#include<time.h>
#include<fstream>
#ifndef _LCC_
#define _LCC_
#endif // _LCC_
#include<mysql.h>
#include<stdio.h>
using namespace std;

void connect(){
    MYSQL mysql_con;
    if(mysql_init(&mysql_con)!=NULL){
        cout<<"init success"<<endl;
    }
    else{
        cout<<"fail"<<endl;
    }


}
vector<long long>addManagerID(vector<long long>id,long long n){
    for(int i=0;i<id.size();i++){
        if(id[i]==n){
            return id;
        }
    }
    id.push_back(n);
    return id;
}
vector<string>addDNO(vector<string>dno,string s){
    for(int i=0;i<dno.size();i++){
        if(dno[i]==s){
            return dno;
        }
    }
    dno.push_back(s);
    return dno;
}
int main()
{
    long index1,index2;
    long long t;
    srand((unsigned)time(NULL));
    vector<long long> workerID,managerID,SALARY,HOURS,tmp;
    vector<string>ENAME,ADRESS;
    string surname[8] = {"赵","钱","孙","李","周","吴","郑","王"};
    string secondname[6] ={"小","立","春","都","多","道"};
    string lastname[6] = {"前","懂","风","美","票","狂"};
    vector<pair<string,string> >PNOANDDNO;
    string province[5]={"广东省","广西省","河南省","黑龙江省","江苏省"};
    string guangdong[5]={"广州市","深圳市","江门市","珠海市","汕头市"};
    string guangxi[5]={"南宁市","梧州市","桂林市","柳州市","玉林市"};
    string henan[5]={"开封市","洛阳市","安阳市","郑州市","新乡市"};
    string heilongjiang[5]={"哈尔滨市","佳木斯市","大庆市","七台河市","鸡西市"};
    string jiangsu[5]={"南京市","徐州市","连云港市","扬州市","苏州市"};
    string P[10] = {"P1","P2","P3","P4","P5","P6","P7","P8","P9","P10"};
    string D[5] = {"D1","D2","D3","D4","D5"};
    string DNAME[5] = {"Research Department","技术部","营销部","管理部","市场部"};
    string PNAME[10]={"SQL Project","闪电","疾风","机锋","雨天","闪烁","锤子","黑水","眼镜蛇","山岩"};
    string DATE[5] = {"1999.9.1","1989.6.4","1980.5.20","1979.6.3","1969.5.3"};
    //build employee
    for(int k=0;k<60;k++){
        string localtmp;
        int localindex2;
        int localindex1 = rand()%5;
        localtmp = province[localindex1];
        switch(localindex1){
            case 0:localindex2 = rand()%5;localtmp += guangdong[localindex2];break;
            case 1:localindex2 = rand()%5;localtmp += guangxi[localindex2];break;
            case 2:localindex2 = rand()%5;localtmp += henan[localindex2];break;
            case 3:localindex2 = rand()%5;localtmp += heilongjiang[localindex2];break;
            case 4:localindex2 = rand()%5;localtmp += jiangsu[localindex2];break;
        }
        ADRESS.push_back(localtmp);
        //cout<<localtmp<<endl;
    }
    for(long long i=4501221970000000;i<4501221975999999;i++){
        tmp.push_back(i);
    }
    for(long j=0;j<6000000;j++){
        index1=rand()%500;
        index2=rand()%6000000;
        t = tmp[index1];
        tmp[index1] = tmp[index2];
        tmp[index2] = t;
    }
    for(long j=0;j<50;j++){
        SALARY.push_back(rand()%8000+2000);
    }
    for(int k=0;k<60;k++){
        workerID.push_back(tmp[k]);
        string tmp1 = surname[rand()%8];
        string tmp2 = secondname[rand()%6];
        string tmp3 = lastname[rand()%6];
        string nametmp = tmp1+tmp2+tmp3;
        ENAME.push_back(nametmp);
    }
    for(int k=50;k<55;k++){
        managerID.push_back(tmp[k]);
    }
    ofstream out("EMPLOYEE.txt");
    out<<'\t'<<"ENAME";
    out<<'\t'<<"ESSN";
    out<<'\t'<<"ADDRESS";
    out<<'\t'<<"SALARY";
    out<<'\t'<<"SUPERSSN";
    out<<'\t'<<"DNO"<<'\n';

    vector<long long>golbalManagerID;
    vector<string> golbalDNO;
    vector<string>PNO,DNO;
    for(int k=0;k<50;k++){
        int randint;
        out<<'\t';
        out<<ENAME[k]<<'\t';
        out<<workerID[k]<<'\t';
        out<<ADRESS[k]<<'\t';
        out<<SALARY[k]<<'\t';
        randint = rand()%5;
        out<<managerID[randint]<<'\t';
        golbalManagerID = addManagerID(golbalManagerID,managerID[randint]);
        out<<D[randint]<<'\n';
        golbalDNO.push_back(D[randint]);
        DNO = addDNO(DNO,D[randint]);
    }
    out.close();
//    cout<<golbalManagerID.size()<<" "<<DNO.size()<<endl;
//    for(int i=0;i<golbalManagerID.size();i++){
//        cout<<golbalManagerID[i]<<":"<<DNO[i]<<endl;
//    }
    out.open("DEPARTMENT.txt");
    out<<'\t'<<"DNAME"<<'\t'<<"DNO"<<'\t'<<"MGRSSN"<<'\t'<<"MGRSTARTDATE"<<'\n';
    for(int i=0;i<5;i++){
        out<<'\t';
        out<<DNAME[i]<<'\t';
        out<<DNO[i]<<'\t';
        out<<golbalManagerID[i]<<'\t';
        out<<DATE[i]<<'\n';
    }
    out.close();


    out.open("PROJECT.txt");
    out<<'\t'<<"PNAME"<<'\t'<<"PNO"<<'\t'<<"PLOCATION"<<'\t'<<"DNO"<<'\n';
    for(int i=0;i<5;i++){
        string tmp;
        tmp = DNO[rand()%5];
        DNO.push_back(tmp);
    }
    for(int i=0;i<10;i++){
        out<<'\t';
        out<<PNAME[i]<<'\t';
        out<<P[i]<<'\t';
        out<<ADRESS[i+50]<<'\t';
        out<<DNO[i]<<'\n';
    }
    vector<vector<string> >DNOTOPNO(5);
    for(int i=0;i<5;i++){
        DNOTOPNO[i].push_back(D[i]);
    }
    for(int i=0;i<DNOTOPNO.size();i++){
        for(int j=0;j<DNO.size();j++){
            if(DNOTOPNO[i][0]==DNO[j]){
                DNOTOPNO[i].push_back(P[j]);
            }
        }
    }
    for(int i=0;i<DNOTOPNO.size();i++){
        cout<<DNOTOPNO[i][0]<<":";
        for(int j=1;j<DNOTOPNO[i].size();j++){
            cout<<DNOTOPNO[i][j]<<" ";
        }
        cout<<endl;
    }
    out.close();
    out.open("WORKS_ON.txt");
    out<<'\t'<<"ESSN"<<'\t'<<"PNO"<<'\t'<<"HOURS"<<'\n';
    for(int i=0;i<50;i++){
        string PNOtmp;
        out<<'\t'<<workerID[i];
        for(int j=0;j<5;j++){
            if(DNOTOPNO[j][0]==golbalDNO[i]){
                PNOtmp = DNOTOPNO[j][rand()%(DNOTOPNO[j].size()-1)+1];
            }
        }
        out<<'\t'<<PNOtmp;
        out<<'\t'<<rand()%64+1<<'\n';
    }
    out.close();
    //rand()%101
    cout << "Hello world!" << endl;
    connect();
    return 0;
}
