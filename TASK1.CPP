#include<iostream>
using namespace std;
int main()
{
    int numsemsters;
    cout<<"Enter number of semsters:";
    cin>>numsemsters;

    double overallgpa=0.0,overallcredits=0.0;
    for(int sem=1;sem<=numsemsters;sem++)
    {
        int numcourses;
        cout<<"\n======================================\n";
        cout<<"\nSEMESTER "<<sem<<":\n";
        cout<<"\n======================================\n";
        cout<<"Enter number of courses in semster "<<sem<<":";
        cin>>numcourses;

        string courseNames[50];
        double Creditshours[50],courseGrades[50];
        double totalcredits=0.0,totalgradepoints=0.0;

        for(int i=0;i<numcourses;i++)
        {
            cout<<"\nEnter name of course "<<i+1<<":";
            cin>>courseNames[i];
            cout<<"Enter credit hours of course "<<courseNames[i]<<":";
            cin>>Creditshours[i];
            cout<<"Enter grade points of course "<<courseNames[i]<<":";
            cin>>courseGrades[i];

            totalcredits+=Creditshours[i];
            totalgradepoints+=Creditshours[i]*courseGrades[i];
        }
        double semgpa=totalgradepoints/totalcredits;
        cout<<"\n-------SEMSTER "<<sem<<" RESULTS-------\n";
        for(int i=0;i<numcourses;i++)
        {
            cout<<"Course: "<<courseNames[i]<<" | Grade: "<<courseGrades[i]<<" | Credit Hours: "<<Creditshours[i]<<endl;

        }
        cout<<"Total Credit (sem " << sem << "):"<<totalcredits<<endl;
        cout<<"Semster GPA:"<<semgpa<<endl;

        overallcredits+=totalcredits;
        overallgpa+=totalgradepoints;
    }
    double cgpa=overallgpa/overallcredits;
    cout<<"\n======================================\n";
    cout<<"\nCUMULATIVE ACADEMIC RECORD:\n";
    cout<<"\n======================================\n";
    return 0;
}