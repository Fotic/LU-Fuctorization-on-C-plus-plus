/*
	Foititis: Paparounas Fotios
	Tmima: Mixanikon Pliroforikis TEI Kavalas
	Mathima: Mathimatika II
*/

#include<iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int n,i,k,j,p;
    double a[10][10],l[10][10]={0},u[10][10]={0},b[10],z[10]={0},x[10]={0};
    double sum;

    cout<<"*****************************\n"
        <<"*** Paparounas Fotis      ***\n"
        <<"*** AEM: 3792             ***\n"
        <<"*****************************\n";

    cout<<"\nDwse to Megethos Pinaka: "; cin>>n;

    cout<<"Dwse stoixia tou Pinaka A: ";
    for(i=1;i<=n;i++)                   //Pername Stoixeia ston 2D Pinaka A
    {
        cout<<"\n-----------\n";
        cout<<"|Grammi "<<i<<" |\n";
        cout<<"-----------\n";
        for(j=1;j<=n;j++)
            cin>>a[i][j];
    }

    cout<<"\nDwse stoixia tou Pinaka B:"<<endl;
    for(i=1;i<=n;i++)                   //Pername Stoixeia ston Pinaka B
        cin>>b[i];

    for(k=1;k<=n;k++)
    {
        u[k][k]=1;
        for(i=k;i<=n;i++) //Ypologismos tou L
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[i][p]*u[p][k];
            l[i][k]=a[i][k]-sum;
        }

        for(j=k+1;j<=n;j++)//Ypologismos tou U
        {
            sum=0;
            for(p=1;p<=k-1;p++)
                sum+=l[k][p]*u[p][j];
            u[k][j]=(a[k][j]-sum)/l[k][k];
        }
    }

    cout<<"\n-----------\n";  //Emfanizoume to L
    cout<<"|    L:    |\n";
    cout<<"-----------\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<l[i][j]<<"  ";
        cout<<endl;
    }

    cout<<"\n-----------\n"; //Emfanizoume to U
    cout<<"|    U:    |\n";
    cout<<"-----------\n";
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<u[i][j]<<"  ";
        cout<<endl;
    }

    for(i=1;i<=n;i++)   //Ypologismos ton X
    {
        sum=0;
        for(p=1;p<i;p++)
            sum+=l[i][p]*z[p];
        z[i]=(b[i]-sum)/l[i][i];
    }

    for(i=n;i>0;i--)
    {
        sum=0;
        for(p=n;p>i;p--)
            sum+=u[i][p]*x[p];
        x[i]=(z[i]-sum)/u[i][i];
    }

    cout<<"\n-----------\n"; //Emfanish ton X
    cout<<"|Apotelesma|\n";
    cout<<"-----------";
    for(i=1;i<=n;i++)
        cout<<"\nX["<<i<<"]: "<<x[i]<<endl<<endl;

    system ( "PAUSE" );
    return 0;
}
