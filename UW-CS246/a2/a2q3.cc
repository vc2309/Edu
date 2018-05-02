#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
 
using namespace std;
 
int main(int argc, char *argv[])
{
    int width = 0;
    char jus = 'l';
    string t;
    string t1;
    string t2;
    switch(argc){
        case 1:
            width = 25;
        break;

        case 3:
            t=argv[1];
            
            if(t=="-w"){ 
            t1=argv[2];
            width=atoi(t1.c_str());
            }
            else {
                cout<<"bad parameter"<<endl;
                exit(0);
            }
        break;

        case 4:
        t=argv[1];
            if(t=="-w"){ 
                t1=argv[2];
                width=atoi(t1.c_str());
                }
                else {
                    cout<<"bad parameter"<<endl;
                    exit(0);
                }
                t2=argv[3];
                if(t2=="-l" || t2=="-c" || t2=="-r"){
                    jus=t2[1];
                }
                else{
                    cout<<"bad parameter"<<endl;
                    exit(0);
                }
        break;
        default:
            cout<<"bad parameters"<<endl;

    }
    // if(argc == 1)
    // {
    //     width = 25;
    // }
    // else
    // {
    //     istringstream ss(argv[1]);
    //     ss >> width;
    // }
    string word;
    int line_length = 0;
    if(jus=='l')
    {while(cin >> word)
        {
            int length = word.length();
            if(length > width && line_length == 0) //check equal to sign
            {
                for(int i = 0; i < length; ++i)
                {
                    if(line_length >= width)
                    {
                        cout << endl;
                        line_length = 0;
                    }
                    cout << word[i];
                    line_length += 1;
                }
     
            }
            else if(length > width - line_length)
            {
                cout << endl;
                line_length = 0;
                for(int y = 0; y < length; ++y)
                {
                    if(line_length >= width)
                    {
                        cout << endl;
                        line_length = 0;
                    }
                    cout << word[y];
                    line_length += 1;
                }
                //line_length = line_length + length;
     
            }
            else
            {
                line_length = line_length + length;
                cout << word;
            }
            
            cout << " ";
            ++line_length;
        }}

else if (jus=='r')
{

    string curl="";
    while(cin >> word)
        {
            //cout<<word<<endl;
            int length = word.length();
            if(length > width && (line_length == 0 || curl.length()>0)) 
            {
                for(int i = 0; i < length; ++i)
                {

                    if(line_length >= width)
                    {
                        for(int j=0;j<(width - line_length);j++){
                            cout<<" ";
                        }
                        cout << curl<<endl;
                        line_length = 0;
                        curl="";
                        continue;
                    }
                    curl=curl+word[i];
                    line_length += 1;
                }
     
            }

            else if(length > width - line_length)
            {
                for(int j=0;j<(width - line_length);j++){
                            cout<<" ";
                        }
                cout << curl<<endl;
                curl="";
                line_length = 0;
                //cout<<"here"<<endl;
                for(int i = 0; i < length; ++i)
                {

                if(line_length >= width)
                    {cout<<"here"<<endl;
                        for(int j=0;j<(width - line_length);j++){
                            cout<<" ";
                        }
                        cout << curl<<endl;
                        //line_length = 0;
                        //curl="";
                        continue;
                    }
                    curl=curl+word[i];
                    line_length += 1;
                }
            }
                //line_length = line_length + length;

                else
            {
                line_length = line_length + length;
                curl=curl+word;
            }

            curl=curl+" ";
            ++line_length;

     
            }



        }


    else{
string curl="";
    while(cin >> word)
        {
            //cout<<word<<endl;
            int length = word.length();
            if(length > width && (line_length == 0 || curl.length()>0)) 
            {
                for(int i = 0; i < length; ++i)
                {

                    if(line_length >= width)
                    {
                        for(int j=0;j<(int((width - line_length)/2));j++){
                            cout<<" ";
                        }
                        cout << curl;
                        for(int j=0;j<(int((width - line_length)/2));j++){
                            cout<<" "<<endl;
                        }

                        line_length = 0;
                        curl="";
                        continue;
                    }
                    curl=curl+word[i];
                    line_length += 1;
                }
     
            }

            else if(length > width - line_length)
            {
                for(int j=0;j<(int((width - line_length)/2));j++){
                            cout<<" ";
                        }
                        cout << curl;
                        for(int j=0;j<(int((width - line_length)/2));j++){
                            cout<<" ";
                        }
                        cout<<endl;
                curl="";
                line_length = 0;
                // cout<<"here"<<endl;
                for(int i = 0; i < length; ++i)
                {

                if(line_length >= width)
                    {cout<<"here"<<endl;
                        for(int j=0;j<(width - line_length);j++){
                            cout<<" ";
                        }
                        cout << curl<<endl;
                        //line_length = 0;
                        curl="";
                        continue;
                    }
                    curl=curl+word[i];
                    line_length += 1;
                }
            }
                //line_length = line_length + length;

                else
            {
                line_length = line_length + length;
                curl=curl+word;
            }

            curl=curl+" ";
            ++line_length;

     
            }



        }




    }
    






