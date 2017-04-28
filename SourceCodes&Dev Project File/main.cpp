#include "organism.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h> 
#include <iostream>  
#include <iomanip>

//METHODS

//Random
int RandomInteger(int low, int high) {
      int k;  
      int dif=high-low+1; 
      k = low + rand() % dif; 
      return k; 
}

//Decrement
void decrement (int k, Organism f[], int s) {   //metaferei mia 8esh pio katw olous tous organismous meta apo to shmeio
for (int j=k; j<s; j++) {                       //pou diagrafhke enas organismos
  if (j<s-1)
  f[j]=f[j+1];
}
}

//Feeding
void feeding (Organism fx, Organism smn, Organism *f[], Organism *s[][100], int *s2, int *ps1, int *ps2, int m1, int n1, bool *seap[][100]) {
if ((fx.getSpecies()!="fytoplakton")&&(fx.getSpecies()!="zwoplakton")) {            //periptwsh o organismos pou kineitai na mhn einai plaktonikos
if ((fx.getTrwwPlakton()==1)&&(smn.getSpecies()=="zwoplakton")) {                   //periptwsh o kinoumenos organismos na trwei plakton kai o akinhtos na einai plakton
if (fx.getSize()>=smn.getSize()) {
fx.setSize(smn.getSize());
for (int i=0; i=s2; i++) {
if (f[i]==smn)
delete f[i];                  //diagrafoume ton sta8ero organismo apo ton pinaka fish[]
decrement(i, f, s2);          //kai allazoume tis 8eseis twn organismwn analoga
s2--;
}
delete s[m1][n1];             //ton diagrafoume kai apo ton pinaka sea[][]
ps1=&m1;
ps2=&n1;
s[ps1][ps2]=&fx;              //edw topo8etoume ton organismo pou epiviwse sto pinaka sea[][]
if (seap[ps1][ps2]==1) {      //an sth kainouria 8esh yparxei molynsh
s[ps1][ps2].getGps();         //ton molynoume
}
}
else {                             //me analogo tropo leitourgoume kai stis ypoloipes periptwseis
smn.setSize(fx.getSize());
for (int i=0; i=s2; i++) {
if (f[i]==fx) {
delete f[i];
decrement(i, f, &s2);
s2--;
}
}
delete s[ps1][ps2];
}
}
else if (((fx.getTrwwPlakton()==0)&&(smn.getSpecies()!="zwoplakton"))||(smn.getSpecies()!="futoplakton")) {
if (fx.getSize()>=smn.getSize()) {
fx.setSize(smn.getSize());
for (int i=0; i=s2; i++) {
if (f[i]==smn)
delete f[i];
decrement(i, f, &s2);
s2--;
}
delete s[m1][n1];
ps1=&m1;
ps2=&n1;
s[ps1][ps2]=&fx;
if (seap[ps1][ps2]==1){
s[ps1][ps2].getGps();
}
}
else {
smn.setSize(fx.getSize());
for (int i=0; i=s2; i++) {
if (f[i]==fx) {
delete f[i];
decrement(i, f, &s2);
s2--;
}
}
delete s[ps1][ps2];
}
}
else if (((fx.getTrwwPlakton()==0)&&(smn.getSpecies()=="zwoplakton"))||(smn.getSpecies()=="fytoplakton")) {
return;
}
else if ((fx.getSpecies()=="zwoplakton")&&(smn.getSpecies()=="fytoplakton")) {
if (fx.getSize()>=smn.getSize()) {
fx.setSize(smn.getSize());
for (int i=0; i=s2; i++) {
if (f[i]==smn)
delete f[i];
decrement(i, f, &s2);
s2--;
}
delete s[m1][n1];
ps1=&m1;
ps2=&n1;
s[ps1][ps2]=&fx;
if (seap[ps1][ps2]==1){
s[ps1][ps2].getGps();
}
}
else {
smn.setSize(fx.getSize());
for (int i=0; i=s2; i++) {
if (f[i]==fx) {
delete f[i];
decrement(i, f, s2);
s2--;
}
}
delete s[ps1][ps2];
}
}
else if ((fx.getSpecies()=="fytoplakton")&&(smn.getSpecies()=="zwoplakton")){
return;
}
} 
}        

//Create
void create(Organism *sea[], Organism *fish[], int s, bool seap[][100]) {
using std::cout;
using std::cin;
int ps1, ps2, choice;
bool z=0;
do {
cout << "Press '1' for sardela\n, '2' for tsipoura\n, '3' for delfini\n, '4' for atherina\n, '5' for zwoplakton\n, '6' for fytoplakton\n";
cin >> choice;                                                                                //dinoume thn epilogh mas me elegxo timwn
}
while ((choice < 1)||(choice > 6));
if (choice==1) {
z=(bool)RandomInteger(0,1);                                                                   //me tyxaio tropo epilegetai to fylo tou
Organism* fish[s]=new Mhplakton ("sardela", 7, 4, z, 1, 0.2, 0.3, 0, 1, 2);
}
else if (choice==2) {
z=(bool)RandomInteger(0,1);
Organism* fish[s]=new Mhplakton ("tsipoura", 5, 5, z, 1, 0.3, 0.5, 0, 0, 2.5);
}
else if (choice==3) {
z=(bool)RandomInteger(0,1);
Organism* fish[s]=new Mhplakton ("delfini", 20, 10, z, 1, 0.7, 1, 0, 0, 5);
}
else if (choice==4) {
z=(bool)RandomInteger(0,1); 
Organism* fish[s]=new Mhplakton ("atherina", 5, 3, z, 1, 0.1, 0.2, 0, 1. 1.5);
}
else if (choice==5) {
Organism* fish[s]=new Zwoplakton ("zwoplakton", 2, 0.001, 1, 0);
}
else {
Organism* fish[s]=new Fytoplakton ("fytoplakton", 1, 0);
}
do {
ps1=RandomInteger(0,99);                       //me tyxaio tropo epilegoume th 8esh pou 8a topo8eth8ei ston pinaka sea[][]
ps2=RandomInteger(0,99);
}
while (sea[ps1][ps2]!=NULL);                  //elegxoume an sth 8esh pou epilex8hke yparxei hdh kapoios organismos
sea[ps1][ps2]=&fish[s];
if (seap[ps1][ps2]==1)                        //elenxoume an sth 8esh pou epilex8hke yparxei hdh molynsh
sea[ps1][ps2].getGps();                       //an yparxei ton molynoume apey8eias
}
}     

//Reproduce                                   //me ton idio peripou tropo leitourgoume kai sth reproduce
void reproduce(Organism *sea[], Organism *fish[], Organism f, int s, bool seap[][100]) {
int ps1, ps2;
bool z=0;
if (f.getSpecies()=="sardela") {
z=(bool)RandomInteger(0,1);
Organism* fish[s]=new Mhplakton ("sardela", 7, 4, z, 1, 0.2, 0.3, 0, 1, 2);
}
else if (f.getSpecies()=="tsipoura") {
z=(bool)RandomInteger(0,1);
Organism* fish[s]=new Mhplakton ("tsipoura", 5, 5, z, 1, 0.3, 0.5, 0, 0, 2.5);
}
else if (f.getSpecies()=="delfini") {
z=(bool)RandomInteger(0,1);
Organism* fish[s]=new Mhplakton ("delfini", 20, 10, z, 1, 0.7, 1, 0, 0, 5);
}
else (f.getSpecies()=="atherina") {
z=(bool)RandomInteger(0,1); 
Organism* fish[s]=new Mhplakton ("atherina", 5, 3, z, 1, 0.1, 0.2, 0, 1. 1.5);
}
do {
ps1=RandomInteger(0,99);
ps2=RandomInteger(0,99);
}
while (sea[ps1][ps2]!=NULL);
sea[ps1][ps2]==&fish[s];
if (seap[ps1][ps2]==1)
sea[ps1][ps2].getGps();
}

//Movement
void movement(int *pos1, int *pos2, int x, int *s2, Organism *fish[], Organism *sea[][100], bool *seapo[][100]) {
int i, j, m, n;
int l, k;
i=pos1;                                           //kratame thn 8esh tou organismou prin na kinh8ei stis metavlhtes i kai j
j=pos2;
m=pos1;
n=pos2;
while ((m==pos1)&&(n==pos2)) {
if (i==0) {                                       //an o organismos vrisketai sthn panw aristera gwnia tou pinaka sea[][] ton kinoume opou borei na kinh8ei mono
if (j==0) {
l=RandomInteger(0,1);                             //me tyxaio tropo dialegoume thn kinhsh pou 8elei na kanei omws den thn oristikopoioume akoma
k=RandomInteger(0,1);
m=k+i;                                            //alla thn apo8hkeyoume stis metavlhtes m kai n
n=l+j;
}
else if (j==99) {                                 //periptwsh o organismos na vrisketai sthn panw de3ia gwnia ektos apo thn parapanw periptwsh
l=RandomInteger(0,1);
k=RandomInteger(-1,0);
m=k+i;
n=l+j;
}
else {                                            //periptwsh na vrisketai opoudhpote allou sthn prwth grammh tou pinaka ektos apo tis parapanw periptwseis
l=RandomInteger(0,1);
k=RandomInteger(-1,1);
m=k+i;
n=l+j;
}

else if (j==0) {                                  //periptwsh na vrisketai sthn katw aristera gwnia tou pinaka ektos   >>           >>
if (i==99) {
k=RandomInteger(0,1);
l=RandomInteger(-1,0);
m=k+i;
n=l+j;
}
else {                                            //periptwsh na vrisketai opoudhpote allou sthn prwth sthlh tou pinaka ektos   >>          >>
k=RandomInteger(0,1);
l=RandomInteger(-1,1);
m=k+i;
n=l+j;
}
}
else if (i==99) {                                 //periptwsh na vrisketai sthn katw de3ia gwnia tou pinaka ektos     >>        >>
if (j==99) {
l=RandomInteger(-1,0);
k=RandomInteger(-1,0);
m=k+i;
n=l+j;
}
else {
k=RandomInteger(-1,0);                            //periptwsh na vrisketai opoudhpote allou sth teleytaia grammh tou pinaka ektos     >>        >>
l=RandomInteger(-1,1);
m=k+i;
n=l+j;
}
}

else if (j==99) {                                 //periptwsh na vrisketai opoudhpote allou sthn teleytaia sthlh tou pinaka ektos       >>       >>
k=RandomInteger(-1,1);
l=RandomInteger(-1,0);
m=k+i;
n=l+j;
}

else {                                            //periptwsh na vrisketai opoudhpote allou ston pinaka ektos apo tis parapanw periptwseis
k=RandomInteger(-1,1);
l=RandomInteger(-1,1);
m=k+i;
n=l+j;
}
}
}

if (sea[m][n]!=null) {                                                                                            //elegxoume an sth kainouria 8esh yparxei hdh kapoios organismos
if ((fish[x].getRep()==1) && (sea[m][n].getRep()==1)) {                                                           //an yparxei elegxoume an o organismos aytos einai anaparagwgisimos
if ((fish[x].getSpecies()==sea[m][n].getSpecies()) && (fish[x].getGender()!=sea[m][n].getGender())) {             //an einai paragwgisimos elegxoume an einai diaforetiko fylo apo ton kinoumeno
s2++;
pos1=&i;                                                                                                          //o kinoumenos organismos afou gonimopoihsei/gonimopoih8ei epistrefei sthn palia tou 8esh
pos2=&j;
if (seapo[m][n]==1){                                                                                              //ton molynoume an h 8esh pou phge g gonimopoihsh htan molysmenh        
sea[pos1][pos2].getGps();
}
reproduce(&sea, &fish, fish[x], &s2, &seapo);                                                                     //kanoume thn anaparagwgh
}
else {
feeding(fish[x], sea[m][n], &fish, &sea, &s2, &pos1, &pos2, m, n, &seapo);
}
}
else { 
feeding(fish[x], sea[m][n], &fish, &sea, &s2, &pos1, &pos2, m, n, &seapo);
}
else {
pos1=&n;
pos2=&m;
sea[m][n]=&fish[x];
if (seapo[pos1][pos2]==1){
sea[pos1][pos2].setGps();
}
}
}
}

//ListOfOrganisms
void lista(Organism f[], int s) {
using std::cout;
using std::cin;
int choice;
cout << "There are" + s + "organisms\n";
for (int i=1; i<=s; i++)
cout << i + ". " + f[i].getSpecies() + "\n"; //#.<name>
do {
cout << "Choose the number of an organism to see details or 0 to exit\n";
do {
cin >> choice;
}
while ((choice >= s)||(choice < 0))
if (choice!=0)
cout << "Species: " + f[choice].getSpecies() + "\nGender: " + f[choice].getGender + "\nSize: " + f[choice].getSize() + "\nAge: " + f[choice].getAge() +"\n"
}
while (choice!=0)
return;
}

//Pollution
void pollution(Organism *sea[][100], bool *seap[][100]) {
using std::cout;
using std::cin;
int x1, y1, x2, y2 ;
cout << "Choose coordinates( x , y ) for top left corner of pollution and then for bottom right corner of pollution\n";
do {
cout << "Choose x for top left corner:\n";
cin >> x1;
}
while (x1 < 0)||(x1 > 100);
do {
cout << "Choose y for top left corner:\n";
cin >> y1;
}
while (y1 < 0)||(y1 > 100);
do {
cout << "Choose x for bottom right corner:\n";
cin >> x2;
}
while (x2 < 0)||(x2 > 100)&&(x2<=x1);
do {
cout << "Choose y for bottom right corner:\n";
cin >> y2;
}
while (((y2 < 0)||(y2 > 100))&&(y2<=y1));
for (int i=0; i<(x2-x1); i++){                                                                                       //molynoume tis 8eseis tou pinaka pou epilex8hke h molynsh
for (int j=0; j<(y2-y1); j++){
seap[i][j]=1
if ((sea[i][j]!=null)&&(sea[i][j].getSpecies()!="zwoplakton")&&(sea[i][j].getSpecies()!="fytoplakton")){
sea[i][j].setGps();                                                                                                  //molynoume olous tous organismous pou yparxoun mesa sth molynsh
}
}
}

}

//Net
void net(int *s, Organism *f[], Organism *sea[][100]){
using std::cout;
int m, n, l, k=0;
m=RandomInteger(0,94); //einai oi syntetagmenes ths panw aristera gwnias tou dixtyou g ayto kai kanw 99-5=94
n=RandomInteger(0,94);
cout << "You throw a 5x5 net and the net's coordinates are " + m + ", " + n + "at it's left top corner and " + (m+5) + ", " + (n+5) + "at it's bottom right corner";
for (int i=m; i<(m+6); i++){   //kanw thn epanalhpsh g na dw pou yparxei organismos sto shmeio pou peta3a to dixty
for (int j=n; j<(n+6); j++){
if (sea[i][j]!=null){    //an yparxei organismos se ayth th 8esh
l=RandomInteger(0,1);  //me tyxaio tropo apofasizetai an 8a piastei sto dixty
if (l=1)
while (k!=-1){
if (sea[i][j]==&f[k]){   //psaxnw to organismo pou vrisketai sth 8esh i, j tou sea ston fish kai ton diagrafw kai aptous dyo pinakes
delete sea[i][j];
delete f[k];
decrement(k, &f, s);
s--;
k=-2;
}
k++;
}
}
}
}
}




//Menu
int menu(Organism *f[], int *r, int *q, int *s2, Organism *sea[][100], bool *seapo[][100]) {
using std::cout;
using std::cin;
char choice;
do {
cout << "1.Press 'SPACE' for RESUME\n" + "2.Press 'C' to CREATE an organism\n" + "3.Press 'L' to see LIST of organisms\n" + "4.Press 'I' to INSERT POLLUTION\n" + "5.Press 'N' to throw net\n" + "6.Press 'R' to RESTART\n" + "7.Press 'Q' to QUIT\n";
cin >> choice;
if (choice==' '){
return;
else if (choice=='c')
s++;
create(&sea, &fish, s2, seapo);
else if (choice=='l')
lista(f, s);
else if (choice=='i')
pollution(&sea, &seapo);
else if (choice=='n')
net(&s2, &f, &sea);
else if (choice=='r')
r=1;
return r;
else if (choice=='q')
q=1;
r=1;
return q;
}
}
while (choice!=' ')&&(choice!='c')&&(choice!='l')&&(choice!='i')&&(choice!='n')&&(choice!='r')&&(choice!='q')
}



//StartingMenu
int startingMenu() {
using std::cout;
char choice;
do {
cout << "1.Press 'S' for START\n" + "2.Press 'Q' to QUIT\n";
cin >> choice;
if (choice=='S') 
return 1;
if (choice=='Q')
return 0;
}
while ((choice!='S')&&(choice!='Q'));
}


//MAIN
int main() {
using std::cout;
using std::cin;
using std::endl;
int size2=16;
srand((unsigned)time( 0 ) );
int position1[size2];
int position2[size2];
Organism sea[100][100];
bool seapol[100][100];
Organism* fish= new Organism[size2];
int y, w;
Organism* fish[0]=new Mhplakton ("sardela", 7, 4, 0, 1, 0.2, 0.3, 0, 1, 2);
Organism* fish[1]=new Mhplakton ("sardela", 7, 4, 1, 1, 0.2, 0.3, 0, 1, 2);
Organism* fish[2]=new Mhplakton ("tsipoura", 5, 5, 1, 1, 0.3, 0.5, 0, 0, 2.5);
Organism* fish[3]=new Mhplakton ("tsipoura", 5, 5, 1, 1, 0.3, 0.5, 0, 0, 2.5);
Organism* fish[4]=new Mhplakton ("delfini", 20, 10, 0, 1, 0.7, 1, 0, 0, 5);
Organism* fish[5]=new Mhplakton ("delfini", 20, 10, 1, 1, 0.7, 1, 0, 0, 5);
Organism* fish[6]=new Mhplakton ("atherina", 5, 3, 0, 1, 0.1, 0.2, 0, 1. 1.5);
Organism* fish[7]=new Mhplakton ("atherina", 5, 3, 1, 1, 0.1, 0.2, 0, 1, 1.5);
Organism* fish[8]=new Zwoplakton ("zwoplakton", 2, 0.001, 1, 0);
Organism* fish[9]=new Zwoplakton ("zwoplakton", 2, 0.001, 1, 0);
Organism* fish[10]=new Zwoplakton ("zwoplakton", 2, 0.001, 1, 0);
Organism* fish[11]=new Zwoplakton ("zwoplakton", 2, 0.001, 1, 0);
Organism* fish[12]=new Fytoplakton ("fytoplakton", 1, 0);
Organism* fish[13]=new Fytoplakton ("fytoplakton", 1, 0);
Organism* fish[14]=new Fytoplakton ("fytoplakton", 1, 0);
Organism* fish[15]=new Fytoplakton ("fytoplakton", 1, 0);
char choice;
int posit1, posit2;
int r=0;
int q=0;


do {                 //h epanalhpsh stamataei an o xrhsths epile3ei na vgei alliws 3anabainei sthn epanalhpsh gia thn opoia borei na kanei restart kai h opoia periexei to kyriws programma
do {                 //synexizetai h epanalhpsh mexri o xrhsths na epile3ei na kanei restart 'h mexri n epile3ei na vgei
if (startingMenu()==0)
q=0;
//Arxikopoihsh
for (int i=0; i<size2; i++) {
position1[i]=0;
position2[i]=0;
}
for (int i=0; i<100; i++) {
for (int j=0; j<100; j++) {
seapol[i][j]=0
}
}
//PutOrganismStarting
y=RandomInteger(0,99);              //topo8etoume ton prwto organismos ston pinaka sea [][]
w=RandomInteger(0,99);
sea[y][w]=fish[0];
position1[0]=y;
position2[0]=w;
for (int x=1; x<size2; x++) {       //topo8etoume kai tous ypoloipous
do {   
y=RandomInteger(0,99);
w=RandomInteger(0,99);
}
while (sea[y][w]!=NULL);
sea[y][w]=fish[x];
position1[x]=y;
position2[x]=w;
}

cout << "Press 'SPACE' for PAUSE\n";
//MovingOrganism
for (int i=0; i=24; i++) { //8ewroume oti ka8e psari kanei 24 kinhseis ana mia mera
for (int a=0; a<size2; a++) { 
fish[a].setGPSSize();  //se kathe kinhsh tou psariou to megethos tou megalwnei symfwna me to gps tou
if (fish[a].getSize()<=0) { //elegxoume an to megethos tou organismou egine arnhtiko h mhden (logw molynshs)
delete fish[a];              //an nai, diagrafoume to psari apton fish
for (int b=0; b<100; b++) {
for (int c=0; c<100; c++) {
if (sea[b][c]==fish[a])
delete sea[b][c];          //diagrafoume to psari apton sea(xarths)
}
}
decrement (a, fish, size2);  //meiwnoume to mege8os tou pinaka fish
size2--;
}
}
for (int l=0; l<size2; l++) {
posit1=position1[l];
posit2=position2[l];
movement(&posit1, &posit2, l, &size2, &fish, &sea, &seapol);
position1[l]=posit1;
position2[l]=posit2;
}
if( kbhit() != 0 ) // Key is pressed
{
switch(getch()) // Get the key
{
case ' ': menu(&fish, &r, &q, &size2, &sea, &seapol); //o kenos xarakthras 'SPACE' 8a mas dwsei to pause
break;
default:
break;
}
}
}
}
while (r==0);
}
while (q==0);
}

