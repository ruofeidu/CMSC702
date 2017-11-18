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


const int K = 20;

char st[1000];
int b[1000];
long long po[30];

unordered_map<long long,int> maps;

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

	po[0]=1;
	for (int i=1;i<30;i++) {
		po[i]=po[i-1]*4;
	}

	while (((dirp=readdir(dp))!=NULL)){
		string s;
		s = dirp->d_name;
		if (s[0]=='S'  && s[1]=='R' && s[2]=='R') {
			n++;
			FILE * pFILE;
			pFILE = fopen(s.c_str(),"r");
					
			//long long run_cnt = 0; 	
			while (fscanf(pFILE, "%s",st)==1) {
				if (b[st[0]]==0 || b[st[1]]==0 || b[st[2]]==0) continue;
				//++run_cnt;
				//if (run_cnt > 10000) break; 
				long long tmp=0;
				int len=strlen(st);
				int Ntot=0;

				for (int i=0;i<K;i++) {
					if (st[i]!='N') 
						tmp+=po[K-1-i]*(b[st[i]]-1);
					else 
						Ntot++;
				}
				if (Ntot==0 && len-K+1>0) maps[tmp]++;

				for (int i = 1; i < len - K + 1; i++) {
					if (st[i-1] == 'N') Ntot--;
					else {
						tmp -= po[K - 1]*(b[st[i - 1]] - 1);
					}
					tmp <<= 2;
					if (st[i + K - 1] == 'N') Ntot++;
					else {
						tmp+=(b[st[i+K-1]]-1);
					}
					if (Ntot==0) {
						//cout<<tmp<<endl;
						maps[tmp]++;
					}
				}
			}
			fclose(pFILE);			
	//		cout<<s<<endl;		
		}	
	}
	closedir(dp);

	

//	cout<<"hi"<<endl;
	printf("%d\n", maps.size()); 
	for (auto& x: maps) {
		printf("%lld\t%d\n", x.first, x.second);
  	}
	
	return 0;
}



