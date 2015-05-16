#include <iostream>
#include <string>
using namespace std;
 
int main()
{	int i, j, M, N, P, count=0, loc;
	string sen, day[] = {"Monday.", "Tuesday.", "Wednesday.", "Thursday.", "Friday.", "Saturday.", "Sunday."};
	bool say=false;
	
	cin >> M >> N >> P;
	string name[M];
	for (i=0; i<M; ++i) cin >> name[i];
	cin.ignore();
	
	while (count < P){
		getline(cin, sen);
		loc = sen.find(":");
		
		for (i=0; i<M; ++i){
			if (sen.substr(0, loc) == name[i]){
				if (sen.substr(loc+2, sen.length()) == "I have the ring."){
					cout << i << ' ' << i << ' ' << '1' << endl;
					say = true;
				}
				if (sen.substr(loc+2, sen.length()) == "I have not the ring."){
					cout << i << ' ' << i << ' ' << '2' << endl;
					say = true;
				}
				
				for (j=0; j<M; ++j){
					if (sen.substr(loc+2, sen.length()) == name[j] + " has the ring."){
						cout << i << ' ' << j << ' ' << '1' << endl;
						say = true;
						break;
					}
					if (sen.substr(loc+2, sen.length()) == name[j] + " has not the ring."){
						cout << i << ' ' << j << ' ' << '2' << endl;
						say = true;
						break;
					}
				}
				
				for (j=0; j<7; ++j){
					if (sen.substr(loc+2, sen.length()) == "Today is " + day[j]){
						cout << i << ' ' << j+1 << ' ' << '3' << endl;
						say = true;
						break;
					}
				}
			} 
		}
		
		++count;
	}
	
	if (not say) cout << "Orz";
	return 0;
}
