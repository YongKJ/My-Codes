#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
class dou{
public:
	dou();
	void set_data();
	int show();
private:
	map<string,int> x;
	map<string,int>::iterator p;
	int n,s[15];
};
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		dou d1;
		d1.set_data();
		if(d1.show())
			cout<<"Case #"<<i<<": Yes"<<endl;
		else
			cout<<"Case #"<<i<<": No"<<endl;
	}
	return 0;
}
dou::dou(){
	string str[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9",  
            "10", "J", "Q", "K", "J1", "J2" };
            for(int i=0;i<15;i++)
            	x[str[i]]=0;
            //for(p=x.begin();p!=x.end();p++)
            	//cout<<p->first<<" "<<p->second<<endl;
}
void dou::set_data(){
	string m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		if(x.find(m)!=x.end())
			x[m]++;
	}
	string str[] = { "2", "3", "4", "5", "6", "7", "8", "9",  
            "10", "J", "Q", "K","A","J1", "J2" };
    for(int i=0;i<15;i++){
    	s[i]=0;
    	for(p=x.begin();p!=x.end();p++)
    		if(str[i]==p->first){
            		s[i]=p->second;
            		break;
            	}
            }
	//for(p=x.begin();p!=x.end();p++)
      //  cout<<p->first<<" "<<p->second<<endl;
}
int dou::show(){
	int t,one=0,two=0,three=0,four=0,a,b,c,k;
	set<int> d1,d2,d3;
	set<int>::iterator p1,p2,q1,q2,t1,t2;
	switch(n){
		case 1:t=1;break;
		//两张
		case 2:
		a=b=0;
		for(p=x.begin();p!=x.end();p++){
			if(p->first=="J1"&&p->second==1)
				a=1;
			else if(p->first=="J2"&&p->second==1)
				b=1;
			else if((p->first!="J1"&&p->first!="J2")&&p->second==2){
				two=1;
				break;
			}
		}
		if(a+b==2||two==1)
			t=1;
		else
			t=0;
		two=0;
		break;
		//三张
		case 3:
		for(p=x.begin();p!=x.end();p++){
			if((p->first!="J1"&&p->first!="J2")&&p->second==3)
				three=1;
		}
			if(three==1)
				t=1;
			else
				t=0;
			break;
		//四张
		case 4:
		for(p=x.begin();p!=x.end();p++){
			if((p->first!="J1"&&p->first!="J2")&&p->second==3)
				three=1;
			else if((p->first!="J1"&&p->first!="J2")&&p->second==1)
				one=1;
			else if((p->first!="J1"&&p->first!="J2")&&p->second==4){
				four=1;
				break;
			}
		}
			if(one+three==2||four==1)
				t=1;
			else
				t=0;
			break;
		//五张
		case 5:
		k=0;
		for(p=x.begin();p!=x.end();p++){
			if((p->first!="J1"&&p->first!="J2")&&p->second==3)
				three=1;
			else if((p->first!="J1"&&p->first!="J2")&&p->second==2)
				two=1;
			else if((p->first!="J1"&&p->first!="J2")&&p->second==1)
				one++;
		}
        for(int i=1;i<13;i++)
            if(s[i]==1&&s[i+1]==1&&s[i+2]==1&&s[i+3]==1&&s[i+4]==1){
            		k=1;
            		break;
            	}
        if(three+two==2||(one==5&&k==1))
        	t=1;
        else
        	t=0;
        break;
        //六张
        case 6:
        a=b=c=0;
        for(p=x.begin();p!=x.end();p++){
			if((p->first!="J1"&&p->first!="J2")&&p->second==3)
				three++;
			else if((p->first!="J1"&&p->first!="J2")&&p->second==2)
				two++;
			else if((p->first!="J1"&&p->first!="J2")&&p->second==1)
				one++;
			else if((p->first!="J1"&&p->first!="J2")&&p->second==4)
				four++;
		}
		for(int i=1;i<13;i++){
            if(s[i]==1&&s[i+1]==1&&s[i+2]==1&&s[i+3]==1&&s[i+4]==1&&s[i+5]==1){
            		a=1;
            		break;
            	}
            else if(s[i]==2&&s[i+1]==2&&s[i+2]==2){
            	b=1;
            	break;
            }
            else if(s[i]==3&&s[i+1]==3){
            	c=1;
            	break;
            }
        }
        if((one==6&&a==1)||(two==3&&b==1)||(three==2&&c==1)||(four==1&&one==2))
        	t=1;
        else
        	t=0;
        break;
        //更多张
        default:
        for(p=x.begin();p!=x.end();p++){
			if((p->first!="J1"&&p->first!="J2")&&p->second==3)
				three++;
			else if((p->first!="J1"&&p->first!="J2")&&p->second==2)
				two++;
			else if((p->first!="J1"&&p->first!="J2")&&p->second==1)
				one++;
			else if((p->first!="J1"&&p->first!="J2")&&p->second==4)
				four++;
		}
		a=b=c=0;
		for(int i=1;i<13;i++){
			if(s[i]==1)
				d1.insert(i);
			else if(s[i]==2)
				d2.insert(i);
			else if(s[i]==3)
				d3.insert(i);
		}
		
		p1=d1.begin();
		if(p1!=d1.end()){
		p2=d1.end();
		a=*p1-*(--p2);
		}
		q1=d2.begin();
		if(q1!=d2.end()){
		q2=d2.end();
		b=(*q1)-*(--q2);
		}
		t1=d3.begin();
		if(t1!=d3.end()){
		t2=d3.end();
		c=(*t1)-*(--t2);
		}
		if((one==n&&a+1==n)||(two==n/2&&b+1==n/2)||(three==n/3&&c+1==n/3)||(three==one&&c+1==(n-one)/3)||(three==two&&c+1==(n-two*2)/3)||(four==1&&two==2&&n==8))
			t=1;
		else
			t=0;
		break;
	}
	return t;

}
/*
样例输入 
3
2 J1 J2
5 A A A 5 6
8 8 8 8 8 9 9 9 9
样例输出 
Case #1: Yes 
Case #2: No 
Case #3: Yes
*/
/*
3
2 J1 J2
5 A A A 5 6
5 10 J Q K A

样例输出

Case #1: Yes
Case #2: No
Case #3: Yes
 */