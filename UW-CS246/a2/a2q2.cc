#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

char encrypt(int x,char dir,char y){
	int ascii;
	switch(dir){
		case 'r':
			if(int(y)>=65 && int(y)<=90) //check if its upper case
			{
				if((int(y)+x)>90){
					ascii=int(y)+x-90+64; //wrap around calculation
				}
				else{
					ascii=int(y)+x;
				}
				
			}
			else if (int(y)>=97 && int(y)<=122)
			{

				if((int(y)+x)>122){
					ascii=int(y)+x-122+96;
				}
				else{
					ascii=int(y)+x;
				}
			}
			else{
				ascii=int(y);
			}
			
			return char(ascii);
		break;
		
		case 'l':
			if(int(y)>=65 && int(y)<=90) //check if its upper case
			{
				if((int(y)-x)<65){
					ascii=91-(65-(int(y)-x)); //wrap around calculation
				}
				else{
					ascii=int(y)-x;
				}
				
			}
			else if(int(y)>=97 && int(y)<=122)
			{

				if((int(y)-x)<97){
					ascii=123-(97-(int(y)-x)); //wrap around calculation
				}
				else{
					ascii=int(y)-x;
				}
			}
			else{
				ascii=int(y);
			}
			
			return char(ascii);
		break;

		default: cout<<"Invalid direction"<<endl;
			exit(0);
	}

}

char decrypt(int x,char dir,char y){
	switch(dir){
		case 'r': return encrypt(x,'l',y);
		break;
		case 'l': return encrypt(x,'r',y);
		break;
		default : cout<<"Invalid direction"<<endl;
			exit(0);
	}
}

void transform(int a,char s, string full){
	string x;
	char cur;
	string trans="";
	char mode='n';
	int ctr=0;
	while(cur!='q' && ctr<full.length()){
		cur=full[ctr];
		// if (cur=='\n')
		// {
		// 	cout<<""<<endl;
		// 	ctr++;
		// 	continue;
			
		// }
		if(cur==' ' && mode!='n'){
			trans=trans+cur;
			ctr++;
			continue;
		}
		if(mode=='e'){
			trans=trans+encrypt(a,s,cur);
		}
		else if(mode=='d'){
			trans=trans+decrypt(a,s,cur);
		}
		else{
			if(cur=='e'){
				mode='e';
				ctr++;
				continue;
			}
			else if(cur=='d'){
				mode='d';
				ctr++;
				continue;
			}
			else if(cur=='q'){
				cout<<trans;
				exit(0);

				break;

			}
		}
		ctr++;
	}
	cout<<trans;
	
	cout<<""<<endl;
}


int main(int argc, char *argv[]) {

	string data="";
	string full="";
	int shift=3;
	string t;
	string t2;
	char dir='r';
	switch(argc){
  	case 1: shift=3;
  			dir='r';
  	break;
  	case 2:
  			t=argv[1];
  			shift=atoi(t.c_str());
  			dir='r';
  	break;
  	case 3: 
  			t=argv[1];
  			shift=atoi(t.c_str());
  			t2=argv[2];
  			dir=(t2=="right")? 'r':'l';
  	break;
  	default: cout<<"error\n";
  }

	while(getline(cin,data))
	{

	// cout<<argc<<endl;
    transform(shift,dir,data);

	}

  

}
