#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string image="*", space=" ";
string line, starline, spaceline;

string MakeFrame(string)
{
    starline+=image+image;
    spaceline+=image+space;
    for(int i=0; i<line.size(); i++)
    {
        starline+=image;
        spaceline+=space;
    }
    starline+=image+image;
    spaceline+=space+image;
    return spaceline, starline;
}
void print(string, string)
{
    cout<<starline<<endl<<spaceline<<endl;
    cout<<image<<space<<line<<space<<image<<endl;
    cout<<spaceline<<endl<<starline<<endl;
}

int main()
{
    string name; 
    int mini=1, maxi=10;
    line="Sveiki, ";
    cout<<"Iveskite savo varda: ";
    cin>>name;
    line+=name+"!";
    print(MakeFrame(line), line);

    return 0;
}