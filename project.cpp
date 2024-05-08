#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
fstream f1;

// login and signup class

class loginandsignup
{
    public:
        string firstname;
        string lastname;
        string email;
        string password;

        // to get data from user during signup

        void getdataforsignup_firstname()
        {

            // first name information

            int i = 0, j = 0;

            cout << "\n First Name : ";
nameinfo:
            cin >> firstname;

            for (i = 0; i < firstname.length(); i++)
            {
                if (firstname[i] >= 'A' && firstname[i] <= 'Z' || firstname[i] >= 'a' && firstname[i] <= 'z')
                {
                    j++;
                }
            }

            if (j == firstname.length())
            {
                cout << "ok";
            }

            else
            {
                cout << "\n Invalid Name  please re enter :";
                i = 0;
                j = 0;
                goto nameinfo;
            }
            system("cls");
        }

        // last name information

        void getdataforsignup_lastname()
        {

            int i = 0, j = 0;
            cout << "\n Last Name : ";
lastnameinfo:
            cin >> lastname;
            for (i = 0; i < lastname.length(); i++)
            {
                if (lastname[i] >= 'A' && lastname[i] <= 'Z' || lastname[i] >= 'a' && lastname[i] <= 'z')
                {
                    j++;
                }
            }
            if (j == lastname.length())
            {
                cout << "ok";
            }

            else
            {
                cout << "\n Invalid Lastname  please re-enter: ";
                i = 0;
                j = 0;
                goto lastnameinfo;
            }
            system("cls");
        }

        // email information
        string getdataforsignup_email()
        {
            cout << "\n Email : ";
            cin >> email;
            return email;
        }
        // password input
        void getdataforsignupo_password()
        {

passwordcheck:
            cout << "\n Password(min 8 letter) : ";
            cin >> password;
            if (password.length() < 8)
            {
                cout << "\n Password is too short";
                goto passwordcheck;
            }
            if (password.length() > 16)
            {
                cout << "\n Password is too long ";
                goto passwordcheck;
            }
            system("cls");

        }


        void signupdata_file()
        {
            ofstream f1("C:/flight management/signupinfo.txt", ios::app);
            if (f1.is_open())
            {
                f1 << firstname << "\n";
                f1 << lastname << "\n";
                f1 << email << "\n";
                f1 << password << "\n";
                f1.close();
                cout << "\n Signup Successful!";
            }
            else
            {
                cout << "\n Unable to open the file.";
            }
            f1.close();
        }

        void logindata_file()
        {
            ifstream f1("C:/flight management/signupinfo.txt");
            if (f1.is_open())
            {
                string checkemail, checkpass;
                int attempts = 0;
                bool validLogin = false;
                while (attempts < 3)
                {
                    cout << "\n Enter Email: ";
                    cin >> checkemail;
                    cout << "\n Enter Password: ";
                    cin >> checkpass;

                    string emailFromFile, passFromFile;
                    bool emailMatch = false, passMatch = false;

                    while (getline(f1, emailFromFile))
                    {
                        getline(f1, passFromFile);

                        if (emailFromFile == checkemail && passFromFile == checkpass)
                        {
                            validLogin = true;
                            emailMatch = true;
                            passMatch = true;
                            break;
                        }
                        else if (emailFromFile == checkemail)
                        {
                            emailMatch = true;
                        }
                        else if (passFromFile == checkpass)
                        {
                            passMatch = true;
                        }
                    }

                    if (validLogin)
                    {
                        cout << "\n Login Successful!";
                        break;
                    }
                    else
                    {
                        if (emailMatch && passMatch)
                        {
                            cout << "\n Incorrect Password. Please try again.";
                        }
                        else if (emailMatch)
                        {
                            cout << "\n Incorrect Password. Please try again.";
                        }
                        else
                        {
                            cout << "\n Email not found. Please try again.";
                        }
                        attempts++;
                    }
                }

                if (!validLogin)
                {
                    cout << "\n Too many login attempts. Exiting program.";
                    exit(0);
                }
                f1.close();
            }
            else
            {
                cout << "\n Unable to open the file.";
            }
        }

};
class Information
{
    public:
        string planeno;  //plane number plate
        string planesource;  // plane source
        string planedestination; //plane destination
        string ticketprice; // price of ticket
        int hr,mi; // hr for hour and mi for minutes
        string day; // day means name of the day
        int d,mth; // mth for month and d for day
        int s; // s for number of seats
        int token; // token for random token

// plane source information

        void getplaneno()
        {
            int i=0,c=0;
            cout<<"\n Enter plane number:";
checkplanenumber:
            cin>>planeno;
            for(i=0; i<planeno.length(); i++)
            {
                if(planeno[i]>=48 && planeno[i]<=57)
                {
                    c++;
                }
            }
            if(c==planeno.length())
            {
                cout<<"\n Ok";
            }
            else
            {
                i=0;
                c=0;
                cout<<"\n Invalid Re-enter: ";
                goto checkplanenumber;
            }
        }

        void getplanesource()
        {
            int i=0,j=0;
            cout<<"\n Enter plane Source :";
            cout<<"\n From :";
enter_planesource:
            cin>>planesource;
            for(i=0; i<planesource.length(); i++)
            {
                if (planesource[i] >= 'A' && planesource[i] <= 'Z' || planesource[i] >= 'a' && planesource[i] <= 'z')
                {
                    j++;
                }
            }
            if(j==planesource.length())
            {
                cout<<"\n ok";
            }
            else
            {
                i=0;
                j=0;
                cout<<"\n Invalid Please re-enter : ";
                goto enter_planesource;

            }
        }
// plane destination information

        void getplanedestination()
        {
            int i=0,j=0;
            cout<<"\n To :";
enter_planedestination:
            cin>>planedestination;
            for(i=0; i<planedestination.length(); i++)
            {
                if (planedestination[i] >= 'A' && planedestination[i] <= 'Z' || planedestination[i] >= 'a' && planedestination[i] <= 'z')
                {
                    j++;
                }
            }
            if(j==planedestination.length())
            {
                cout<<"\n ok";
            }
            else
            {
                i=0;
                j=0;
                cout<<"\n Invalid re_enter :";
                goto enter_planedestination;
            }

        }
        // ticket price information

        void getticketprice()
        {
            int i=0,c=0;
            cout<<"\n Enter Ticket price :";
enter_ticketprice:
            cin>>ticketprice;
            for(i=0; i<ticketprice.length(); i++)
            {
                if(ticketprice[i]>=48 && ticketprice[i]<=57)
                {
                    c++;
                }
            }
            if(c==ticketprice.length())
            {
                cout<<"\n ok";
            }
            else
            {
                cout<<"\n Invalid price re-enter :";
                i=0;
                c=0;
                goto enter_ticketprice;
            }
        }
        // time of plane departure

        void gettime()
        {
            string hour,min;
            int i=0,j=0,k=0,l=0,hr=0,mi=0;
            cout<<"\n Enter Time(Hour:Min in 24 hour format) ";
enter_time:
            cin>>hour;
            cin>>min;
            if(hour.length()<=2 && min.length()<=2)
            {
                for(i=0; i<hour.length(); i++)
                {
                    if(hour[i]>=48 && hour[i]<=57)
                    {
                        j++;
                    }
                }
                for(k=0; k<min.length(); k++)
                {
                    if(min[k]>=48 && min[k]<=57)
                    {
                        l++;
                    }
                }
                if(j==hour.length() && l==min.length())
                {
                    goto datecheck;
                }
                else
                {
                    cout<<"\n Invalid Re-enter : ";
                    i=0;
                    j=0;
                    k=0;
                    l=0;
                    goto enter_time;
                }
            }
            else
            {
                cout<<"\n Too long Invalid re-enter:";
                goto enter_time;

            }
datecheck:
            stringstream ss(hour);
            stringstream ww(min);
            if(ss>>hr && hr<24 && ww>>mi && mi<60)
            {
                cout<<"\n ok";
            }
            else
            {
                cout<<"\n Invalid Re-enter : ";
                i=0;
                j=0;
                k=0;
                l=0;
                hr=0;
                mi=0;
                goto enter_time;
            }
            cout<<"\n Time ="<<hr<<":"<<mi;


        }

        void getdate()
        {
            string month,date;
            int i=0,j=0,k=0,l=0,d=0,mth=0,x=0;
            cout<<"\nEnter Day:";
enter_day:
            cin>>day;
            for(x=0; x<day.length(); x++)
            {
                day[x]=toupper(day[x]);
            }
            if(day=="SUNDAY" || day=="MONDAY" || day=="TUESDAY"|| day=="WEDNESDAY"|| day=="THURSDAY"|| day=="FRIDAY"|| day=="SATURDAY")
            {
                cout<<"\n ok";
            }
            else
            {
                cout<<"\nInvalid day Re-enter : ";
                goto enter_day;

            }
            cout<<"\n Enter day and month :";
enter_month:
            cin>>date;
            cin>>month;
            if(date.length()<=2 && month.length()<=2)
            {
                for(i=0; i<date.length(); i++)
                {
                    if(date[i]>=48 && date[i]<=57)
                    {
                        j++;
                    }
                }
                for(k=0; k<month.length(); k++)
                {
                    if(month[k]>=48 && month[k]<=57)
                    {
                        l++;
                    }
                }
                if(j==date.length() && l==month.length())
                {
                    goto checkdate;
                }
                else
                {
                    cout<<"\n Invalid Re-enter :";
                    i=0;
                    j=0;
                    k=0;
                    l=0;
                    goto enter_month;
                }

            }
            else
            {
                cout<<"\n Too long Re_enter :";
                goto enter_month;
            }
checkdate:
            stringstream ss(date);
            stringstream ww(month);
            if(ss>>d && d<=31 && ww>>mth && mth<=12)
            {
                cout<<"\n ok";
            }
            else
            {
                cout<<"\n Invalid Re-enter : ";
                i=0;
                j=0;
                k=0;
                l=0;
                d=0;
                mth=0;
                goto enter_month;
            }
            if(mth==2)
            {
                if(d>29)
                {
                    cout<<"\n Invalid re-enter :";
                    i=0;
                    j=0;
                    k=0;
                    l=0;
                    d=0;
                    mth=0;
                    goto enter_month;

                }
            }
            cout<<"\n Date="<<day<<"/"<<mth<<"/"<<d;

        }



        void numberofseat()
        {
            string seats;
            int i=0,j=0,s=0;
            cout<<"\n Enter number of seats :";
enter_seats:
            cin>>seats;
            for(i=0; i<seats.length(); i++)
            {
                if(seats[i]>=48 && seats[i]<=57)
                {
                    j++;
                }
            }
            if(j==seats.length())
            {
                goto checkseat;
            }
            else
            {
                cout<<"\n Invalid Number Re-Enter:";
                i=0;
                j=0;
                goto enter_seats;
            }
checkseat:
            stringstream ss(seats);
            if(ss>>s && s<=600)
            {
                cout<<"\n ok";
            }
            else
            {
                cout<<"\n Invalid Re-enter:";
                i=0;
                j=0;
                s=0;
                goto enter_seats;

            }

        }
        void planeinfo_file()
        {
            ofstream f1("C:/flight management/info.txt", ios::app);
            if (f1.is_open())
            {
                f1   << planeno << " "
                     << planesource << " "
                     << planedestination << " "
                     << ticketprice << " "
                     << hr << " "
                     << mi << " "
                     << mth << " "
                     << d << " "
                     << token << endl;
                f1.close();
                cout << "\nFlight information saved to file." << endl;
            }
            else
            {
                cout << "\nUnable to open file." << endl;
            }
        }

        void flight_deletion()
        {
            int planeNumber;
            cout << "Enter the plane number to delete: ";
            cin >> planeNumber;

            ifstream f1("C:/flight management/info.txt");
            ofstream tempFile("C:/flight management/temp.txt");

            if (f1.is_open() && tempFile.is_open())
            {
                int tempPlaneNo;
                string tempLine;

                while (getline(f1, tempLine))
                {
                    istringstream iss(tempLine);
                    if (iss >> tempPlaneNo)
                    {
                        if (tempPlaneNo == planeNumber)
                        {
                            cout << "Flight with plane number " << planeNumber << " deleted." << endl;
                            continue; // Skip writing this line to temp file
                        }
                    }
                    tempFile << tempLine << endl;
                }

                f1.close();
                tempFile.close();

                remove("C:/flight management/info.txt");
                rename("C:/flight management/temp.txt", "C:/flight management/info.txt");
            }
            else
            {
                cout << "\nUnable to open file." << endl;
            }
        }


        void bookflight()
        {
        	int temptoken;
            ifstream f1("C:/flight management/info.txt");
            if(f1.is_open())
            {
            	string source,destination;
            	bool validBooking=false;
            	
            	cout<<"\n Enter Source :";
            	cin>>source;
            	cout<<"\n Enter Destination: ";
            	cin>>destination;
            	
            	string sourceFromFile,destinationFromFile;
            	bool sourceMatch=false, destinationMatch=false;
            	
            	while(getline(f1, planesource))
            	{
            		getline(f1, planedestination);
            		cout<<planedestination;
            		
            		if(planesource == source && planedestination == destination)
            		{
            			validBooking=true;
            			sourceMatch=true;
            			destinationMatch=true;
            			break;
					}
					else if(planesource == source)
					{
					  	sourceMatch=true;
					}
					else if(planedestination == destination)
					{
						destinationMatch=true;
					}
				}
			
				if(validBooking==true)
				{
				  cout<<"\n Your Flight is Successfully booked:";
				   srand(static_cast<unsigned int>(time(0)));
                temptoken = rand() % 9000 + 1000;
                  cout << "\n Token: " << temptoken;
                  cout<<"\n Take This Token to get boarding pass..";
              }
            
				f1.close();
			}
			
			else
			{
				cout<<"\n Unable to open File :";
			}
			token=temptoken;
        }


        void cancelBooking()
        {
            int cancelToken;
            cout << "\nEnter the token number to cancel the flight: ";
            cin >> cancelToken;

            if(cancelToken=token)
            {
            	cout<<"\n Your Flight Has been cancelled :";
			}
			else
			{
				cout<<"\n Invalid Token Number :";
				exit(0);
			}
        }


};
// Function to check the character
// is an alphabet or not

bool isChar(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Function to check the character
// is an digit or not

bool isDigit(const char c)
{
    return (c >= '0' && c <= '9');
}

// Function to check email id is
// valid or not

bool is_valid(string checkemail)
{
    // Check the first character
    // is an alphabet or not

    if (!isChar(checkemail[0]))
    {

        // If it's not an alphabet
        // email id is not valid

        return 0;
    }
    // Variable to store position
    // of At and Dot

    int At = -1, Dot = -1;

    // Traverse over the email id
    // string to find position of
    // Dot and At

    for (int i = 0;
            i < checkemail.length(); i++)
    {

        // If the character is '@'

        if (checkemail[i] == '@')
        {

            At = i;
        }

        // If character is '.'

        else if (checkemail[i] == '.')
        {

            Dot = i;
        }
    }
    int k = 0, i = 0;
    for (i = At + 1; i < checkemail.length(); i++)
    {
        string check, check1;
        check1 = "yahoo.com";
        check = "gmail.com";
        if (checkemail[i] == check[k] || checkemail[i] == check1[k])
        {
            k++;
        }
        else
        {
            k = 0;
            return 0;
        }
    }
    if (k == 9)
    {
        return 1;
        k = 0;
        i = 0;
    }

    // If At or Dot is not present

    if (At == -1 || Dot == -1)
        return 0;

    // If Dot is present before At

    if (At > Dot)
        return 0;

    // If Dot is present at the end

    return !(Dot >= (checkemail.length() - 1));
}

int main()
{
    int selection=0,i=0,j=0;
    string a;
    string checkemail;
    loginandsignup data1;
    Information data2;
startmenue:
    cout<<"\n\t\t\t\t _______________________________________________\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|******************-WELCOME-********************|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|                   ______     _____            |\n";
    cout<<"\t\t\t\t|                  /          /                 |\n";
    cout<<"\t\t\t\t|                 /_____     /____              |\n";
    cout<<"\t\t\t\t|                /          /                   |\n";
    cout<<"\t\t\t\t|               /______    /			|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|	      ROYAL EAGLE FLIGHT CO.        	|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|      		 1.log in			|\n";
    cout<<"\t\t\t\t|       	 2.sign up			|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|	    www.Royal_Eagle.com		        |\n";
    cout<<"\t\t\t\t|		 Kathmandu,Nepal           	|\n";
    cout<<"\t\t\t\t|_______________________________________________|\n";
    cout<<"enter selection : ";
loginsignupselection:
    cin>>a;
    if(a.length()==1)
    {
        for(i=0; i<a.length(); i++)
        {
            if(a[i]>=49 && a[i]<=57)
            {
                j++;
            }
        }
        if(j==a.length())
        {
            goto transferatoselect;
        }
        else
        {
            cout<<"\n Invalid Re-enter:";
            i=0;
            j=0;
            goto loginsignupselection;
        }
    }
    else
    {
        cout<<"\n Invalid Re-enter:";
        goto loginsignupselection;
    }
transferatoselect:
    stringstream zz(a);
    if(zz>>selection)
    {
        cout<<"\n OK";
    }
    else
    {
        cout<<"\n Invalid Re-enter :";
        i=0;
        j=0;
        goto loginsignupselection;
    }
    switch (selection)
    {
        case 1:
        {
            system("cls");
            data1.getdataforsignup_firstname();
            data1.getdataforsignup_lastname();
invalidemail:
            checkemail = data1.getdataforsignup_email();

            bool ans = is_valid(checkemail);

            // Print the result
            if (ans == 1)
            {
                cout << "\nok";
            }
            else
            {
                cout << "\nInvalid Email" << endl;
                goto invalidemail;
            }
            system("cls");

            data1.getdataforsignupo_password();
            data1.signupdata_file();
        }
        break;

        case 2:
        {
            system("cls");
            data1.logindata_file();
        }


        break;

        default:
            cout<<"\n Invalid Input :";
            system("cls");
            goto startmenue;
    }
    int selection1=0;
    string b;
    i=0;
    j=0;
menue2:
    cout<<"\n\t\t\t\t _______________________________________________\n";
    cout<<"\t\t\t\t|royaleagle.co		                	|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|-----------------------------------------------|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|      		1.owner/crew			|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|-----------------------------------------------|\n";
    cout<<"\t\t\t\t|       	 2.customer	        	|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|-----------------------------------------------|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|						|\n";
    cout<<"\t\t\t\t|_______________________________________________|\n";
    cout<<"\n Enter Selection :";
loginsignupselection1:
    cin>>b;
    if(b.length()==1)
    {
        for(i=0; i<b.length(); i++)
        {
            if(b[i]>=49 && b[i]<=57)
            {
                j++;
            }
        }
        if(j==b.length())
        {
            goto transferbtoselect1;
        }
        else
        {
            cout<<"\n Invalid Re-enter:";
            i=0;
            j=0;
            goto loginsignupselection1;
        }
    }
    else
    {
        cout<<"\n Invalid Re-enter:";
        goto loginsignupselection1;
    }
transferbtoselect1:
    stringstream zx(b);
    if(zx>>selection1)
    {
        cout<<"\n OK";
    }
    else
    {
        cout<<"\n Invalid Re-enter :";
        i=0;
        j=0;
        goto loginsignupselection1;
    }

    switch(selection1)
    {
        case 1:
        {
            cout<<"\n Welcome To Owner Section ";
            int selection2=0,i=0,j=0;
            string c;
            cout<<"\n\t\t\t\t _______________________________________________\n";
            cout<<"\t\t\t\t|royaleagle.co		                	|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|-----------------------------------------------|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|      		1.Add	Flight			|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|-----------------------------------------------|\n";
            cout<<"\t\t\t\t|       	 2.Remove Flight        	|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|-----------------------------------------------|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|_______________________________________________|\n";
            cout<<"\n Enter coice : ";
loginselection2:
            cin>>c;
            if(c.length()==1)
            {
                for(i=0; i<c.length(); i++)
                {
                    if(c[i]>=49 && c[i]<=57)
                    {
                        j++;
                    }
                }
                if(j==c.length())
                {
                    goto transferctoselect2;
                }
                else
                {
                    cout<<"\n Invalid Re-enter:";
                    i=0;
                    j=0;
                    goto  loginselection2;
                }
            }
            else
            {
                cout<<"\n Invalid Re-enter:";
                goto  loginselection2;
            }
transferctoselect2:
            stringstream zy(c);
            if(zy>>selection2)
            {
                cout<<"\n OK";
            }
            else
            {
                cout<<"\n Invalid Re-enter :";
                i=0;
                j=0;
                goto  loginselection2;
            }
            switch(selection2)
            {
                case 1:
                {
                    system("cls");
                    data2.getplaneno();
                    data2.getplanesource();
                    data2.getplanedestination();
                    data2.getticketprice();
                    data2.gettime();
                    data2.getdate();
                    data2.numberofseat();
                    data2.planeinfo_file();
                }
                break;
                case 2:
                {
                    data2.flight_deletion();
                }
                break;
                default:
                    cout<<"\n Invalid Input :";
            }
        }
        break;
        case 2:
        {
            cout<<"\n Welcome to Royal Flight :";
            int selection3=0,i=0,j=0;
            cout<<"\n\t\t\t\t _______________________________________________\n";
            cout<<"\t\t\t\t|royaleagle.co		                	|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|-----------------------------------------------|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|      		1.Book Flight			|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|-----------------------------------------------|\n";
            cout<<"\t\t\t\t|       	 2.Cancle Flight        	|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|-----------------------------------------------|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|						|\n";
            cout<<"\t\t\t\t|_______________________________________________|\n";
            cout<<"\n Enter coice : ";
            string c1;
customerselectionc3:
            cin>>c1;
            Information data3;
            if(c1.length()==1)
            {
                for(i=0; i<c1.length(); i++)
                {
                    if(c1[i]>=49 && c1[i]<=57)
                    {
                        j++;
                    }
                }
                if(j==c1.length())
                {
                    goto transfertoselectionc3;
                }
                else
                {
                    cout<<"\n Invalid Re-enter :";
                    i=0;
                    j=0;
                    goto customerselectionc3;
                }
            }
            else
            {
                cout<<"\n Invalid Re-enter:";
                goto customerselectionc3;
            }
transfertoselectionc3:
            stringstream zc(c1);
            if(zc>>selection3)
            {
                cout<<" ";
            }
            else
            {
                cout<<"\n Invalid Re-enter:";
                i=0;
                j=0;
                goto customerselectionc3;
            }
            switch(selection3)
            {
                case 1:
                {
                    data3.bookflight();
                    exit(0);
                }
                break;

                case 2:
                {
                    data2.cancelBooking();
                    exit(0);
                }
                break;

                default:
                    cout<<"\n Invalid Input:";
            }

        }
        default:
            cout<<"\n Invalid Input :";
            system("cls");
            goto menue2;
    }

    return 0;
}
