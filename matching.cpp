/*******************************************************/
 /*       2nd Takehome Assignment         */
 /*Instructions :                    */
 /*   Data should be input to the program using text */
 /*     file (EX: test.txt)            */
 /*   INPUT FORMAT:                 */
 /*     4 5 5                   */
 /*     1 8                    */
 /*     1 5                    */
 /*     2 6                    */
 /*     3 9                    */
 /*     4 7                    */
 /*   first three integers (n,m and e)        */
 /*     n: number of left hand nodes        */
 /*     m: number of right hand node        */
 /*     e: number of incedent edges        */
 /*    next integer(g[u][v])            */
 /*      g[u][v]: adjecent verteces        */
 /*******************************************************/
 #include <iostream>
 #include <vector>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <queue>
 #include <fstream>
 using namespace std;
 #define MAX 10000 //maximum allowed couples
 #define NIL 0
 #define INF (1<<28) //infinity
 vector<int> G[MAX]; // G[0]= NIL u G1[G[1---n]] u G2[G[n+1---n+m]]
 int n,m,e,match[MAX],dist[MAX];
 //Breadth first search
 bool bfs() {
   int i, u, v, len;
   queue<int> Q;  //an integer queue
   for(i=1; i<=n; i++) {
     if(match[i]==NIL) { //i is not matched
       dist[i] = 0;
       Q.push(i);
     }
     else dist[i] = INF;
   }
   dist[NIL] = INF;
   while(!Q.empty()) {
     u = Q.front();
     Q.pop();
     if(u!=NIL) {
       len = G[u].size();
       for(i=0; i<len; i++) {
         v = G[u][i];
         if(dist[match[v]]==INF) {
           dist[match[v]] = dist[u] + 1;
           Q.push(match[v]);
         }
       }
     }
   }
   return (dist[NIL]!=INF);
 }
 //depth first search
 bool dfs(int u) {
   int i, v, len;
   if(u!=NIL) {
     len = G[u].size();
     for(i=0; i<len; i++) {
       v = G[u][i];
       if(dist[match[v]]==dist[u]+1) {
         if(dfs(match[v])) {
           match[v] = u;
           match[u] = v;
           return true;
         }
       }
     }
     dist[u] = INF;
     return false;
   }
   return true;
 }
 int hopcroft_karp() {
   int matching = 0, i;
   // match[] is assumed NIL for all vertex in G
   while(bfs())
     for(i=1; i<=n; i++)
       if(match[i]==NIL && dfs(i))
         matching++;
   return matching;
 }
 //read data file in to an array
 int openDataFile(char *filename){
   int A, B;
   ifstream infile();
   if (!infile) { //fill not found
     printf("There was a problem opening file %s for reading.\n",filename);
     return 0;
   }
   printf("Opened %s for reading.\n", filename); //file opened
   cin >> n >> m >>e; // for perfect matching n=m
   while (cin >> A >> B) { //read adjecent verteces
     G[A].push_back(B);
   }
 }
 //main method starts here
 int main() {
   printf("\n*******************************\n\tFind Stable Cuples\n*******************************\n");
   char filename[256] = {0};
   int NumOfMatches,i;
   printf("Enter data file name : ");
   //scanf("%s",&filename);
   filename="C:\Users\cyber\Desktop\codechef\input.txt";
   openDataFile(filename);
   while(1){
     int choice;
     printf("\n*******************************\n\tFind Stable Cuples\n*******************************\n");
     printf("Enter 1 : Find Optimal Solution\n");
     printf("Enter 2 : Add New Data File\n");
     printf("Enter 0 : Exit\n");
     printf("\nEnter :");
     scanf("%d",&choice);
     if(choice==1){
       openDataFile(filename);
       NumOfMatches=hopcroft_karp(); //find matching perfect matching couples
       printf("Number of couples matched : %d\n",NumOfMatches);
       for(i=1;i<=n;i++){
         printf("%d matched with %d\n",i,match[i]);
       }
     }else if(choice==2){
       printf("Enter data file name : ");
       scanf("%s",&filename);
     }
     else if(choice==0){
       printf("Program Terminated\n");
       exit(0);
     }
     else{
       printf("Error : Wrong Input\n");
     }
   }
   return 0;
 }
