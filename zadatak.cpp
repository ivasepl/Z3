#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "implementacija_reda_pokazivac.h"
//#include "implementacija_reda_polje.h"
using namespace std;
int vrijeme=0;
int adi=1,bdi=1,cdi=1,ddi=1,edi=1;

void prioritet(int br){
	switch(br)
	{
		case 1: cout<<"VIP";break;
		case 2: cout<<"Invalid";break;
		case 3: cout<<"Trudnica";break;
		case 4: cout<<"Umirovljenik";break;
		case 5: cout<<"Ostali";break;	
	}	
}

void radi(int br){
	switch(br)
	{
		case 1: cout<<"Predaja/Preuzimanje posiljke";break;
		case 2: cout<<"Placanje racuna";break;
		case 3: cout<<"Uplata lutrije";break;
		case 4: cout<<"Western Union";break;
		case 5: cout<<"Ezotv";break;	
	}		
}


klijent generiram(int ci){
	klijent osoba;
	string c="TF";
	string g="MZ";
	char r;
	 char mimena[10][30]={"Marko","Ante","Ivan","Luka","Mateo","Stjepan","Dario","Dorijan","Nikola"};
	 char zimena[10][30]={"Ana","Tea", "Lana","Mateja","Sandra","Lea","Mirna","Tatjana","Senka","Vesna"};
     char prezimena[10][30]={"Nikolic","Lukic","Ivancic","Antolic","Spahic","Darcic","Grcic","Biondic","Stipic"};
	
	if(ci==3){
		strcpy(osoba.ime,zimena[rand()%9]);
		strcpy(osoba.prezime,prezimena[rand()%9]);
		osoba.dan=1+rand()%31;
		osoba.mj=1+rand()%12;
		osoba.god=1970+rand()%21;
		osoba.spol=g[1];
		return osoba;
	}
	else if(ci==4){
		r=c[rand()%2];
		if(r=='T'){
		strcpy(osoba.ime,zimena[rand()%9]);
		osoba.spol=g[1];
     	}
		else if(r=='F'){
		strcpy(osoba.ime,mimena[rand()%9]);
		osoba.spol=g[0];
		}
		strcpy(osoba.prezime,prezimena[rand()%9]);
		osoba.dan=1+rand()%31;
		osoba.mj=1+rand()%12;
		osoba.god=1920+rand()%20;
		return osoba;	
	}
	else{
		r=c[rand()%2];
		if(r=='T'){
		strcpy(osoba.ime,zimena[rand()%9]);
		osoba.spol=g[1];
     	}
		else if(r=='F'){
		strcpy(osoba.ime,mimena[rand()%9]);
		osoba.spol=g[0];
		}
		strcpy(osoba.prezime,prezimena[rand()%9]);
		osoba.dan=1+rand()%31;
		osoba.mj=1+rand()%12;
		osoba.god=1950+rand()%50;	
		return osoba;
	}
	
	
}

//prednost osoba s vecim prioritetom za glavni red
void prednost(red* Q, klijent os){
	red *Q2 = InitQ(Q2);
		klijent pom2, pom;
	bool da = false;
	bool jednom = true, odobreno = false;
		while(!IsEmptyQ(Q)){
		pom = FrontQ(Q);
		EnQueueQ(pom,Q2);
		DeQueueQ(Q);	
	}

		while(!IsEmptyQ(Q2))
		{
		pom2 = FrontQ(Q2);
		if(da && os.ci<pom2.ci&&jednom){
			EnQueueQ(os,Q);
			jednom=false;
			cout<<endl<<"**************************************";
			cout<<endl<<"Dosla je osoba s vecim prioritetom: "<<endl;
			cout<<endl<<"Ime: "<<os.ime<<endl<<"Prezime: "<<os.prezime<<endl<<"Spol: "<<os.spol<<endl<<"Datum rodenja: "<<os.dan<<"."<<os.mj<<"."<<os.god<<endl;
			prioritet(os.ci);
			cout<<endl;
			radi(os.di);
			cout<<endl;
			cout<<endl<<"**************************************"<<endl;
			odobreno=true;
			}
		
		EnQueueQ(pom2,Q);
		DeQueueQ(Q2);
		da = true;	
	}
	if(odobreno==false){
	EnQueueQ(os,Q);	
	cout<<endl<<"Dosla je nova osoba: "<<endl;
	cout<<endl<<"Ime: "<<os.ime<<endl<<"Prezime: "<<os.prezime<<endl<<"Spol: "<<os.spol<<endl<<"Datum rodenja: "<<os.dan<<"."<<os.mj<<"."<<os.god<<endl;
	prioritet(os.ci);
	cout<<endl;
	radi(os.di);
	cout<<endl;	
	}
	
}



// ispis osoba horoskopskog znaka jarac, mladi od 40 za uslugu uplate lutrije
void ispisiPosebne(red *Q){
		red* Q2=InitQ(Q2);
		while(!IsEmptyQ(Q)){
		klijent pom;
		pom = FrontQ(Q);
		if(((pom.mj==12&&pom.dan>=22)||(pom.mj==1&&pom.dan<=20))&&((2014-pom.god)<40)&&pom.di==3)
		{
		cout<<endl<<"Ime: "<<pom.ime<<endl<<"Prezime: "<<pom.prezime<<endl<<"Spol: "<<pom.spol<<endl
		<<"Datum rodenja: "<<pom.dan<<"."<<pom.mj<<"."<<pom.god<<endl;
		prioritet(pom.ci);
		cout<<endl;
		radi(pom.di);
		cout<<endl;
		}
		EnQueueQ(pom,Q2);
		DeQueueQ(Q);	
	}
	while(!IsEmptyQ(Q2)){
		klijent pom2;
		pom2 = FrontQ(Q2);
		EnQueueQ(pom2,Q);
		DeQueueQ(Q2);	
	}
}

//Ulazak osoba u postu!
void unos(red *Q){
	red *Q2 = InitQ(Q2);
	
	srand(time(0));
	bool prva = false;
	klijent osoba,p,z;
	int N;
	cout<<endl<<"Koliko osoba ulazi? ";
	cin>>N;
	for(int i = 0; i<N;i++){
		osoba.ai=10+rand()%491;
		osoba.bi=80+rand()%791;
		osoba.ci=1+rand()%5;
		osoba.di=1+rand()%5;
		p=generiram(osoba.ci);
		p.ai=osoba.ai;
		p.bi=osoba.bi;
		p.ci=osoba.ci;
		p.di=osoba.di;
		prednost(Q,p);
		vrijeme+=p.ai;
		z=FrontQ(Q);
		if(vrijeme>z.bi){
			cout<<endl<<endl<<"Osoba: "<<endl<<"Ime: "<<z.ime<<endl<<"Prezime: "<<z.prezime<<endl<<"Spol: "<<z.spol<<
			endl<<"Datum rodenja: "<<z.dan<<"."<<z.mj<<"."<<z.god<<endl;
			prioritet(z.ci);
			cout<<endl;
			radi(z.di);
			cout<<endl<<endl<<"je zavrsila! \nNa redu je sljedeca osoba! "<<endl;
			DeQueueQ(Q);
			vrijeme = 0;
		}	
	}
	cout<<endl<<endl<<"Ako ima ispisujem sve osobe mlade od 40 koje su horoskopskog znaka jarac! \nTe cekaju na uplatu lutrije"<<endl;
	ispisiPosebne(Q);
	
}
//ispis osoba u pošti
void ispisi(red *Q){
	red* Q2=InitQ(Q2);
	while(!IsEmptyQ(Q)){
		klijent pom;
		pom = FrontQ(Q);
		cout<<endl<<"Ime: "<<pom.ime<<endl<<"Prezime: "<<pom.prezime<<endl<<"Spol: "<<pom.spol<<endl<<"Datum rodenja: "
		<<pom.dan<<"."<<pom.mj<<"."<<pom.god<<endl;
		prioritet(pom.ci);
		cout<<endl;
		radi(pom.di);
		cout<<endl;
		EnQueueQ(pom,Q2);
		DeQueueQ(Q);	
		}
	while(!IsEmptyQ(Q2)){
		klijent pom2;
		pom2 = FrontQ(Q2);
		EnQueueQ(pom2,Q);
		DeQueueQ(Q2);	
		}
}
//ispis osoba po šalterima
void ispisi2(red *Q, int posao){
	red* Q2=InitQ(Q2);
	while(!IsEmptyQ(Q)){
		klijent pom;
		pom = FrontQ(Q);
		if(pom.di==posao){
		
		cout<<endl<<"Ime: "<<pom.ime<<endl<<"Prezime: "<<pom.prezime<<endl<<"Spol: "<<pom.spol<<endl<<"Datum rodenja: "
		<<pom.dan<<"."<<pom.mj<<"."<<pom.god<<endl;
		prioritet(pom.ci);
		cout<<endl;
		radi(pom.di);
		cout<<endl;
		}
		EnQueueQ(pom,Q2);
		DeQueueQ(Q);	
		}
	while(!IsEmptyQ(Q2)){
		klijent pom2;
		pom2 = FrontQ(Q2);
		EnQueueQ(pom2,Q);
		DeQueueQ(Q2);	
		}
}

//izlazak trudnica
void trudnice(red *Q){
	red* Q2=InitQ(Q2);
	while(!IsEmptyQ(Q))
			{
				klijent pom;
				pom = FrontQ(Q);
				EnQueueQ(pom,Q2);
				DeQueueQ(Q);	
			}
	while(!IsEmptyQ(Q2))
			{
				klijent pom2;
				pom2 = FrontQ(Q2);
				if(pom2.ci!=3 &&pom2.di!=5)
						{
							EnQueueQ(pom2,Q);	
						}
		DeQueueQ(Q2);
		
			}
	ispisi(Q);
}

//dodavanje osoba s vecim prioritetom na pocetak reda za brzu liniju
void prednost2(red* Q, klijent os){
	red *Q2 = InitQ(Q2);
	klijent pom2, pom;
	bool jednom = true, odobreno = false;
	while(!IsEmptyQ(Q))
	{
		pom = FrontQ(Q);
		EnQueueQ(pom,Q2);
		DeQueueQ(Q);	
	}
	while(!IsEmptyQ(Q2))
		{
			pom2 = FrontQ(Q2);
			if(jednom&&os.ci>=pom2.ci){
				if(pom2.ci==os.ci&&os.di<pom2.di){
						EnQueueQ(os,Q);
						jednom=false;
						odobreno = true;	
						}
				}
			EnQueueQ(pom2,Q);
			DeQueueQ(Q2);	
		}
	if(odobreno==false){
		EnQueueQ(os,Q);	
		}
}

//funkcija za prebacivanje osoba u brzu liniju
void rekurzija(red *Q, red *N){
     if(IsEmptyQ(Q)) return; 
     klijent pom=FrontQ(Q);
     DeQueueQ(Q);
     rekurzija(Q, N);
     if(pom.ci==4)prednost2(N,pom);
     else if(pom.di==1&&adi<=2)prednost2(N,pom),adi++;
     else if(pom.di==2&&bdi<=2)prednost2(N,pom),bdi++;
     else if(pom.di==3&&cdi<=2)prednost2(N,pom),cdi++;
     else if(pom.di==4&&ddi<=2)prednost2(N,pom),ddi++;
     else if(pom.di==5&&edi<=2)prednost2(N,pom),edi++;
     else EnQueueQ(pom,Q);
     return;         
}
void rekurzija_okreni(red *Q){
     if(IsEmptyQ(Q)) return;
     klijent pom=FrontQ(Q);
     DeQueueQ(Q);
     rekurzija_okreni(Q);
     EnQueueQ(pom, Q);    
}


int main(){
	int izbor;
	red *Q = InitQ(Q);
	red *N = InitQ(N);
	
	do{
	cout<<endl<<"---------------POSTA--------------";
	cout<<endl<<"1.Ulazak ljudi";
	cout<<endl<<"2.Izlazak trudnica";
	cout<<endl<<"3.Ispis svih";
	cout<<endl<<"4.Salter brzih usluga";
	cout<<endl<<"5.Ispisi ljude na brzoj liniji i svaki pojedini salter"<<endl;
	cin>>izbor;
	switch(izbor){
		
		case 1: unos(Q);break;
		case 2: trudnice(Q);
				cout<<endl<<"--------------------------------------"<<endl;
				cout<<endl<<"Trudnice koje cekaju za salter EvoTv su \nnapustile red zbog predugog cekanja";
				cout<<endl<<"--------------------------------------"<<endl;
				break; 
		case 3: ispisi(Q);break;
		case 4: rekurzija(Q,N), rekurzija_okreni(Q),rekurzija_okreni(N); 
				cout<<endl<<"--------------------------------------"<<endl;
				cout<<endl<<"Ljudi su prebaceni u brzu liniju"<<endl;
				cout<<endl<<"--------------------------------------"<<endl;
				break;
		case 5: cout<<endl<<"--------------------------------------"<<endl;
				cout<<endl<<"Ispis brzog reda: ";
				cout<<endl<<"--------------------------------------"<<endl;
				ispisi(N);
				cout<<endl<<"---------------------------------------------"<<endl;
				cout<<endl<<"Ispis saltera predaja/preuzimanje posiljke: "<<endl;
				cout<<endl<<"----------------------------------------------"<<endl;
				ispisi2(Q,1);
				cout<<endl<<"--------------------------------------"<<endl;
				cout<<endl<<"Ispis saltera placanje racuna: "<<endl;
				cout<<endl<<"--------------------------------------"<<endl;
				ispisi2(Q,2);
				cout<<endl<<"--------------------------------------"<<endl;
				cout<<endl<<"Ispis saltera uplata lutrije: "<<endl;
				cout<<endl<<"--------------------------------------"<<endl;
				ispisi2(Q,3);
				cout<<endl<<"--------------------------------------"<<endl;
				cout<<endl<<"Ispis saltera Western Union: "<<endl;
				cout<<endl<<"--------------------------------------"<<endl;
				ispisi2(Q,4);
				cout<<endl<<"--------------------------------------"<<endl;
				cout<<endl<<"Ispis saltera EzoTv: "<<endl;
				cout<<endl<<"--------------------------------------"<<endl;
				ispisi2(Q,5);
		
		break;
	}	
			
	}while(izbor!=9);	
}
