#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct kayit{
  char isim[16];
  char soyisim[21];
  char tc[12];
  char hastalik[21];
  char Cinsiyet[6];
  };

void menuHazirla();
int hastaEkle();
int hastalariListele();
int aramaYap(char *);


void menuHazirla(){
  printf(" ");
 
}


int hastaEkle(){

  struct kayit yeniKayit;
  FILE *ptVeritabani;

  if((ptVeritabani=fopen("hastaVeritabani.txt","a"))==NULL){
    return -1;
  }
  system("cls");
  printf("\n\n");
  printf("Isim giriniz (En fazla 15 karakter): ");
  scanf("%s",yeniKayit.isim);

  printf("Soyisim giriniz (En fazla 20 karakter): ");
  scanf("%s",yeniKayit.soyisim);

  printf("Vatandaslik numaranizi giriniz (En fazla 11 karakter): ");
  scanf("%s",yeniKayit.tc);
  
  printf("Hastalýk giriniz (En fazla 30 karakter): ");
  scanf("%s",yeniKayit.hastalik);
   printf("Cinsiyet(en fazla 10 karakter): ");
  scanf("%s",yeniKayit.Cinsiyet);


  fprintf(ptVeritabani, "\n%s\t%s\t%s\t%s", yeniKayit.isim, yeniKayit.soyisim, yeniKayit.tc, yeniKayit.hastalik, yeniKayit.Cinsiyet);

  fclose(ptVeritabani);
  return 0;
}


int hastalariListele(){

  FILE *ptVeritabani;
  struct kayit aktifKayit;
  if((ptVeritabani=fopen("hastaVeritabani.txt","r"))==NULL){
    return -1;
  }

  system("cls");
  printf("\n\nIsim\t\tSoyisim\t\tTC\t\t\tHastalik\t\t\tCinsiyet\n");
  printf("----\t\t-------\t\t--\t\t\t--------\t\t\t--------\n\n");
  
  while(!feof(ptVeritabani)){
    fscanf(ptVeritabani,"%s%s%s%s",&aktifKayit.isim, &aktifKayit.soyisim, &aktifKayit.tc, &aktifKayit.hastalik, aktifKayit.Cinsiyet);
    printf("%s\t\t",aktifKayit.isim);
    printf("%s\t\t",aktifKayit.soyisim);
	printf("%s\t\t",aktifKayit.tc); 
	printf("%s\n",aktifKayit.hastalik);
	printf("%s\n",aktifKayit.Cinsiyet);  
  }

  fclose(ptVeritabani);
  return 0;
}

int aramaYap(char *arananIsim){

  FILE *ptVeritabani;
  struct kayit aktifKayit;
  int bulunan=0;

  if((ptVeritabani=fopen("hastaVeritabani.txt","r"))==NULL){
    return -1;
  }
 
  while(!feof(ptVeritabani)){
    fscanf(ptVeritabani,"%s%s%s%s",&aktifKayit.isim, &aktifKayit.soyisim, &aktifKayit.tc, &aktifKayit.hastalik, &aktifKayit.Cinsiyet);

    if(!strcmp(arananIsim, aktifKayit.isim)){ 
      system("cls");
	  printf("\n\nIsim\t\tSoyisim\t\tTC\t\t\tHastalik\t\t\tCinsiyet\n");
      printf("----\t\t-------\t\t--\t\t\t--------\t\t\t-------\n\n");
	  printf("%s\t\t",aktifKayit.isim);
      printf("%s\t\t",aktifKayit.soyisim);
      printf("%s\t\t",aktifKayit.tc);
	  printf("%s\n",aktifKayit.hastalik);
	  printf("%s\n",aktifKayit.Cinsiyet);  
	 
      
      bulunan++;
    }
  }

  fclose(ptVeritabani);
  return bulunan;
}
void sifreligiris(); 
int main(void) {

sifreligiris();
return (EXIT_SUCCESS);
}

void sifreligiris(){ 
char gercek_sifre[12]="furkan123"; 
char sifre[12]={0}; 
char gercek_kullaniciadi[11]="aykut123";
char kullaniciadi[11]={0};  
int sonuc1=2;
int sonuc2=2;

printf("Kullanici adi: ");
scanf("%s",kullaniciadi);
printf("Sifre : ");
scanf("%s",sifre);

sonuc1=strcmp(sifre,"furkan123");
sonuc2=strcmp(kullaniciadi,"aykut123");

if(sonuc1==0 && sonuc2==0){

	
  char secim='0';
  char aranacakIsim[16];
  int numaraAra=-1;

  menuHazirla();

  do{
    printf("\n\n****************************************\n****************************************\n****                                ****\n****       Hastane Otomasyonu       ****\n****                                ****\n****      1. Hasta Ekle             ****\n****      2. Hastalari Listele      ****\n****      3. Hasta Ara              ****\n****      4. Cikis                  ****\n****                                ****\n****************************************\n****************************************\n\n\nSeciminiz:  ");
    secim = putch(getch());

    switch (secim){
      case '1':
        if (hastaEkle()==0){ 
          printf("\nHasta kaydi basariyla yapildi.");
        }else{
          printf("\nHATA: Hasta kaydi eklenemedi!");
        }
        break;
      case '2':
        if (hastalariListele()==0){ 
          printf("\nHasta listesi listelendi.");
        }else{
          printf("\nHATA: Hasta listesi listelenemedi!");
        }
        break;
      case '3':
        printf("\nAranacak ismi giriniz (En fazla 15 karakter): ");
        scanf("%s",aranacakIsim);

        numaraAra = aramaYap(aranacakIsim);
        if (numaraAra == 0){ 
          printf("\nAranan isim kayitlarda bulunamadi.");
        }else {
          if(numaraAra > 0)
            printf("\ntoplam %d kayit bulundu.",numaraAra);
          else
            printf("\nHATA: Hasta aranamadi!");
        }
        break;
        case '4':
        	printf("Cinsiyetini giriniz(en fazla 10 karakter)");
        	break;
      case '5':
       
        return ;
        break;
      default:
        printf("\nlutfen 1-4 arasinda bir secim yapiniz.");

    }
  }while(secim!=4);

  return ;
}
else {
printf("Kullanci adi veya sifre hatali\n");
sifreligiris(); 
}

}

