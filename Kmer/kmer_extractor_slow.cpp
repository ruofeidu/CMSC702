#include <cstdio>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>
#include <string>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;


const int K = 25;

char st[1000];
int b[1000];

unordered_map<string,int> maps;

int main(int argc,char *argv[]){
	int i,j,k;
	DIR *dp;
	struct dirent *dirp;
	int n=0;
	if (argc!=2){
		printf("a single argument is required\n");
		return 0;
	}
	if((dp=opendir(argv[1]))==NULL)
		printf("can't open %s",argv[1]);

	memset(b,0,sizeof(b));
	b['A']=1;
	b['C']=2;
	b['G']=3;
	b['T']=4;
	b['N']=5;
	maps.clear();
	
	while (((dirp=readdir(dp))!=NULL)){
		string s;
		s = dirp->d_name;
		if (s[0]=='S'  && s[1]=='R' && s[2]=='R') {
			n++;
			FILE * pFILE;
			pFILE = fopen(s.c_str(),"r");
					
			long long run_cnt = 0; 	
			while (fscanf(pFILE, "%s",st)==1) {
				if (b[st[0]]==0 || b[st[1]]==0 || b[st[2]]==0) continue;
				++run_cnt;
				if (run_cnt > 10000) break; 
				int len=strlen(st);
				string ss(st,len);
				string tmp;
				
				bool flag;
				for (int i=0;i<len-K+1;i++) {
					j=i+K-1;
					tmp=ss.substr(i,K);
					flag=true;
					for (int k=0;k<K;k++) if (tmp[k]=='N') {
						flag=false;
						break;
					}
					if (flag)
						maps[tmp]++;
					//cout<<tmp<<" "<<maps[tmp]<<endl;
				}
			}
			fclose(pFILE);			
	//		cout<<s<<endl;		
		}	
	}
	closedir(dp);
	

//	cout<<"hi"<<endl;
	cout << maps.size() << endl; 
	for (auto& x: maps) {
    	cout << x.first << "\t" << x.second << endl;
  	}
	
	return 0;
}



