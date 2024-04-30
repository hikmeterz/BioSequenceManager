#include <stdio.h>

int esitMi(const char array1[],const char array2[]);
char* directive_ayir(const char Str[]);
int stringToInteger(char s[]);
void remove_seq(int pos);
void display_all();
void display(int pos);
void clip(int pos,int star,int end);
void copy_seq(int pos1,int pos2);
void swap(int pos1,int start1,int pos2,int start2);
void insert(int pos , char sequence[]);
char*  boslukayir(char str1[],int x);
void max_overlap(int pos1,int pos2);
char *sequence[200]; //row

int main(){


	//arrayın rowlarını # ile doldurma..
	
	for(int i=0;i<200;i++){
		sequence[i]="#";
		
	}

	

	char c;
	int i=0;
	char lines[1000];
	char *directive;


	//textinputtaki directivleri  character o okuyor..
	while ((c = getchar()) != EOF) {
    		lines[i]=c;
		i++;    		
		if (c=='\n'){
      			lines[i-1]='\0';//satır okunmus hali...
			directive=directive_ayir(lines);
		
			

			if(esitMi(directive,"remove")==1){//ilk bosluga kadar directive remove esitse..
				//printf("%s\n",sequence[5]);
	
		
				char *position;//positionı tutan array..
		
		
				position=boslukayir(lines,1);		
		
		
				int pos=stringToInteger(position);					
		

				//printf("%i\n",pos);

				remove_seq(pos);

				//printf("%s\n",sequence[pos]);
							
			}else if(esitMi(directive,"display-all")==1){//directive display-all a esitse.
				display_all();
		
			}else if(esitMi(directive,"display ")==1){

				char *position;//positionı tutan array..
		
		
				position=boslukayir(lines,1);		
		
		
				int pos=stringToInteger(position);					
		

				//printf("%i\n",pos);

				display(pos);

				//printf("%s\n",sequence[pos]);

			}else if(esitMi(directive,"clip")==1){
				char *starArray;
				char *endArray;
				char *position;//positionı tutan array..
		
		
				position=boslukayir(lines,1);		
				starArray=boslukayir(lines,2);
				endArray=boslukayir(lines,3);
		
		
				int pos=stringToInteger(position);					
				int star=stringToInteger(starArray);
				int end=stringToInteger(endArray);
		

				//printf("%i %i %i\n",pos,star,end);
		
				//int x= star + end;

				//printf("%i\n",x);

				clip(pos,star,end);

				//printf("%s\n",sequence[13]);




			}else if(esitMi(directive,"copy")==1){

				char *position1;//positionı tutan array..
				char *position2;
		
				position1=boslukayir(lines,1);		
				position2=boslukayir(lines,2);
		
		
				int pos1=stringToInteger(position1);					
				int pos2=stringToInteger(position2);
		
		

				//printf("%i %i\n",pos1,pos2);
		
				//int x= pos1 + pos2;

				//printf("%i\n",x);

				copy_seq(pos1,pos2);

				//printf("%s\n",sequence[13]);
				//printf("%s\n",sequence[12]);


			}else if(esitMi(directive,"swap")==1){
				
				char *position1;
				char *start1Array;
				char *position2;//positionı tutan array..
				char *start2Array;

				position1=boslukayir(lines,1);		
				start1Array=boslukayir(lines,2);
				position2=boslukayir(lines,3);
				start2Array=boslukayir(lines,4);

				int pos1=stringToInteger(position1);					
				int start1=stringToInteger(start1Array);
				int pos2=stringToInteger(position2);
				int start2=stringToInteger(start2Array);


				//printf("%i%i%i%i\n",pos1,start1,pos2,start2);

				//int x= start1+pos1+start2+pos2;

				//printf("%i\n",x);
		
				swap(pos1,start1,pos2,start2);

		
			}else if(esitMi(directive,"max-overlap")==1){
				char *position1;
		
				char *position2;//positionı tutan array..
		
				position1=boslukayir(lines,1);		
				position2=boslukayir(lines,2);
		
				int pos1=stringToInteger(position1);					
		
				int pos2=stringToInteger(position2);
		


				//printf("%i %i\n",pos1,pos2);

				//int x=+pos1+pos2;

				//printf("%i\n",x);
		
				max_overlap(pos1,pos2);

			}else if(esitMi(directive,"insert")){

				char *position;
		
				char *seq1;
		
				position=boslukayir(lines,1);		
				seq1=boslukayir(lines,2);
		
				int pos1=stringToInteger(position);					
		
		

				//printf("%i\n",pos1);

				char sequencecopy[1000];
				int i=0;		
				for(i;seq1[i]!='\0';i++){
			
					sequencecopy[i]=seq1[i];

				}

				sequencecopy[i]='\0';

		
		
				insert(pos1,sequencecopy);
			
			}else if(esitMi(directive,"quit ")==1)
				break;				
			
			i=0;	
			
		}
		
  	}


	return 0;


}

int esitMi(const char Str1[],const char Str2[]){
	
	int say=0;
	for(int i=0;Str1[i]!='\0';i++){//Str1 uzunlugu
		
		say++;

	}
	int say1=0;
	for(int i=0;Str2[i]!='\0';i++){//Str1 uzunlugu
		
		say1++;

	}


	
	if(say==say1){

		for(int i=0;i<say;i++){
			
			if(Str1[i]==Str2[i]){
				continue;

			}
			else
				return 0;//esit degil.

		}
		
		return 1;
	}

	else
		return 0;

}
char* directive_ayir(const char Str[]){//Each directive consists of the name of the directive followed by 0 or more arguments, separated by spaces o yuzden display-all dan sonra bir bosluk olması lazım.
	char directive[100];
	directive[0]='\0';
		
	for(int i=0;Str[i]!='\0';i++){
		directive[i]=Str[i];
		if(Str[i]==' '){
			
			directive[i]='\0';			
			break;

		}

	}

	char * s=directive;
	return s;
		
}

int lengthSay(char s[]){
	int length=0;
	


	for(int i=0;s[i]!='\0';i++){
		
		length++;
	}


	return length;


}


int stringToInteger(char s[]){//Stringi integera ceviren metod.
		
		if(s[0]!='-'){
			int sonuc = 0, carpim = 1;
			int length=0;
			for(int i=0;s[i]!='\0';i++){
				length++;

			}

			for (int i =length-1;i >= 0; i--){ //clipten onceki metotlar icin de kontrol et.
				if(s[i]>='0' && s[i]<='9'){
		
					sonuc += (s[i]-'0') * carpim;
					carpim *= 10;
				}else
					continue;
			
			}	
			 return sonuc;

		}else

			return -20;//Negatif bir rakam gonderdik.Rastgele
}

void remove_seq(int pos){

	if(pos<200&&pos>=0)
		sequence[pos]="#";

	else
		printf("There is no sequence at pos\n");

}

void display_all(){
	int row=0;
	for(int i=0;i<200;i++){

		printf("%i.row= %s\n",row,sequence[i]);
		row++;

	}

}


void display(int pos){

	if(pos>=0 && pos<200){
		if(sequence[pos][0]!='#')
			printf("%s\n",sequence[pos]);
		else
			printf("Error empty sequence\n");
	}
	else
		printf("Error there is no sequence at pos");
}

void clip(int pos,int star,int end){

	
	if((pos>=0 && pos<200)){
		
		char *seq=sequence[pos];
		int lengthofseq=lengthSay(seq);

		if((star<=lengthofseq&&star>=0) && (star<end) && (end<=lengthofseq)){

			
			if(seq[0]!='#'){
				
				char clipped[100];
				
				int i=star;
				
				int j=end;
				int clipCounter=0;
							
				for(i ; i<=j ; i++){//Hata burda...
					clipped[clipCounter]=seq[i];
					clipCounter++;
				

				}

				
				
				clipped[clipCounter]='\0';
				sequence[pos]=clipped;

			}else
				printf("This sequence is empty\n");
		}else

			printf("The start and end index are not available for this seq.\n");	

	}else{
		printf("False indexes.\n");
	}

} 

void copy_seq(int pos1, int pos2){
	

	char* seq=sequence[pos1];

	if(seq[0]!='#'){
		sequence[pos2]=sequence[pos1];
	}

	else
		printf("There is no sequency in pos1\n");

	
}
void swap(int pos1,int start1,int pos2,int start2){

	if((pos1>=0 && pos2 <200)&&(pos2>=0 && pos2<200)){
		
		int lengthofpos1=lengthSay(sequence[pos1]);
		printf("%d\n",lengthofpos1);
		int lengthofpos2=lengthSay(sequence[pos2]);
		printf("%d\n",lengthofpos2);

		if(start1<lengthofpos1 && start2<lengthofpos2){

			//printf("%s\n",sequence[pos1]);

			char seq1[1000];
			for(int i = 0; i < lengthofpos1 ; i++){
				seq1[i] = sequence[pos1][i];
			}			
	
			char tail1[100];
			
			int counter1=0;//0
			for(int i=start1;seq1[i]!='\0';i++){
				

				tail1[counter1]=seq1[i];
				counter1++;

			}
					printf("%s\n",seq1);
					printf("%s\n",tail1);
			
			tail1[counter1]='\0';//Buraları kontrol et.
			


			char seq2[1000];
			for(int i = 0; i < lengthofpos2 ; i++){
				seq2[i] = sequence[pos2][i];
			}	
				//printf("%s\n",seq2);
			char tail2[100];
			int counter2=0;
			for(int i=start2;seq2[i]!='\0';i++){
				
				tail2[counter2]=seq2[i];//tail2 i yazdı....
				counter2++;
				
			}
				tail2[counter2]='\0';
				//printf("%s\n",tail2);
		
			
			
		
			//swap islemleri...

			int lengthoftail1=lengthSay(tail1);
			int lengthoftail2=lengthSay(tail2);
		
			seq1[start1+lengthoftail2]='\0';

						
			
						
    			for (int j = 0; tail2[j] != '\0'; ++j, ++start1) {
        			seq1[start1] = tail2[j];
    			}
			
			sequence[pos1]=seq1;
			
			printf("%s\n",sequence[pos1]);
	


			
			seq2[start2+lengthoftail1]='\0';

			for (int j = 0; tail1[j] != '\0'; ++j, ++start2) {
        			seq2[start2] = tail1[j];
    			}	
		



			sequence[pos2]=seq2;

			printf("%s\n",sequence[pos2]);
			


		}else if(start1==lengthofpos1 || start2==lengthofpos2|| start1<0 || start2<0){

			printf("The other tail is already appended.. or start1 or start2 less than zero");

		}

		else{

			printf("False start indexes.\n");	
		
		}




	}



	

}

void insert(int pos,char sequenceArray[]){

	//int lengthOfpos=lengthSay(sequence[pos]);
	if(pos<200 && pos>=0){
		int i=0;
		for(i;sequenceArray[i]!='\0';i++)
			sequence[pos]=sequenceArray;


		sequence[pos][i+1]='\0';
	}

	else
	   printf("There is no sequence at this pos");


	printf("%s\n",sequence[pos]);


}
void max_overlap(int pos1,int pos2){

    if((pos1>=0 && pos1<200)&& (pos2>=0 && pos2<200)){

	    char *s1=sequence[pos1];
	    char *s2=sequence[pos2];
	
	    int i = 0;
	    char overlap[1000];
	    //overlap[0]='\0';

	    while (*s1 != '\0' && *s2 != '\0'){
		if (*s1 == *s2){ 
			overlap[i]=*s1;
			i++;
			
		}
		s1++;
		s2++;
			    
	    }
	    overlap[i]='\0';
	    printf("The length of overlap is: %i, And the overlapping sequence is %s\n",i,overlap);

    }else
	printf("There is no sequence at pos1 and pos2\n");


}
char*  boslukayir(char str1[],int x){

	char newString[10][10];	//ilk kutu satır. diger 10 kutu uzunlugu.
	int len=lengthSay(str1);
	int j=0; 
	int ctr=0;
    	for(int i=0;i<=len;i++){

        if(str1[i]==' '||str1[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            newString[ctr][j]=str1[i];
            j++;
        }
    }

    char* arguments;
    arguments=newString[x];
	
    return arguments;


}


