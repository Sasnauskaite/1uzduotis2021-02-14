#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

string image="*", space=" ";
string line, starline, spaceline;
int numspaces;

string MakeNewLine()
{
    string newline;
    newline+=image+space;
    for(int i=0; i<numspaces; i++)
    {
        newline+=space;
    }
    newline+=line;
    for(int i=0; i<numspaces; i++)
    {
        newline+=space;
    }
    newline+=space+image;
    return newline;
}
void addNumspaces()
{
    for(int i=0; i<numspaces; i++)
    {
        starline+=image;
        spaceline+=space;
    }
}
string MakeFrame(string)
{
    starline+=image+image;
    spaceline+=image+space;
    addNumspaces();
    for(int i=0; i<line.size(); i++)
    {
        starline+=image;
        spaceline+=space;
    }
    addNumspaces();
    starline+=image+image;
    spaceline+=space+image;
    return spaceline, starline;
}
string wholeFrame()
{
    string frame;
    frame+=starline+"\n";
    for(int i=0; i<numspaces; i++)
    {
        frame+=spaceline+"\n";
    }
    frame+=MakeNewLine()+"\n";
    for(int i=0; i<numspaces; i++)
    {
        frame+=spaceline+"\n";
    }
    frame+=starline+"\n";
    return frame;
}
void print(string, string)
{
    cout<<wholeFrame();
}
bool Gender(string name)
{
    string lastLetter;
    bool status = true;
    for (int i=0; i<name.size(); i++)
    {
        lastLetter=name[i];
    }
    if(lastLetter != "s")
    {
        status = false;
    }
    return status;
}
int check(int mini, int maxi)
{
    if(numspaces<mini)
    {
        cout<<"Jusu ivestas skaicius yra uz intervalo ["<<mini<<";"<<maxi<<"] ribu. "<<endl;
        exit(0);
    }
    if(numspaces>maxi)
    {
        cout<<"Jusu ivestas skaicius yra uz intervalo ["<<mini<<";"<<maxi<<"] ribu. "<<endl;
        exit(0);
    }
}
int main()
{
    string name; 
    int mini=1, maxi=10;
    line="Sveiki, ";
    cout<<"Iveskite savo varda: ";
    cin>>name;
    if(Gender(name))
    {
        line="Sveikas, ";
        name.back()='i';
    }
    else
    {
        line="Sveika, ";
    }
    cout<<"Iveskite kiek tarpu nuo "<<mini<<" iki "<<maxi<<" norite savo remelyje: ";
    cin>>numspaces;
    
    check(mini, maxi);
    line+=name+"!";
    print(MakeFrame(line), line);

    return 0;
}
