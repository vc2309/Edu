#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;

int count_words(string line){
	int counter=0;
	bool w=false;
	for(int i=0;i<line.length();i++){
		if(line[i]!=' '){
			w=true;
		}
		else{
			if (w==true)
			{
				++counter;
				w=false;
			}

		}
		
		
	}
	if(w==true){
			++counter;
		}
return counter;

}

void count(bool w, bool l, bool c, string files[], int size){
int t_l=0;
int t_w=0;
int t_c=0;
string line="";
	for(int x=0;x<size;x++)
	{	
		int lc,cc,wc=0;
		ifstream i_f;
		i_f.open(files[x]);

		while(getline(i_f,line))
		{
			wc+=count_words(line);
			cc+=line.length();
			// cout<<lc<<endl;
			lc+=1;
			// lmax++;
			// cmax=cmax+lines.length()+1;
		}
i_f.close();
		if (l==true)
		{
			cout<<"\t"<<lc;
		}
		if (w==true)
		{
			cout<<"\t"<<wc;
		}
		if (c==true)
		{
			cout<<"\t"<<cc;
		}
		cout<<" "<<files[x]<<endl;

		
		t_l+=lc;
		t_w+=wc;
		t_c+=cc;
	}
if(size>1)
{if (l==true)
		{
			cout<<"\t"<<t_l;
		}
		if (w==true)
		{
			cout<<"\t"<<t_w;
		}
		if (c==true)
		{
			cout<<"\t"<<t_c;
		}
		cout<<" "<<"total"<<endl;}
}

int main(int argc, char *argv[]) 
{

	bool w,l, c= false;
	string *files=new string[argc];
	int j=0;
	for (int i = 1; i < argc; ++i) 
	{
		string t=argv[i];
		if (t=="-c")
		{
			c=true;
		}
		else if(t=="-w")
		{
			w=true;
		}
		else if(t=="-l")
		{
			l=true;
		}
		else
		{
			files[j]=argv[i];
			j++;
		}
	}
	

	if(w==false&&c==false&&l==false)
	{
		
		c=true;
		l=true;
		w=true;
	}
count(w,l,c,files,j);
return 0;
}

	

