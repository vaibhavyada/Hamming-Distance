#include<stdio.h>
#include<string.h>
# define N strlen(gen_poly)
char data[28];
char rdata[28];
char check_value[28];
char gen_poly[10];
int data_length,i,j;
int c= 0;

void XOR(){
	for(j=1;j<N;j++){
		check_value[j] = ((check_value[j] == gen_poly[j])?'0':'1');
	}
}

void crc(){
	for(i=0;i<N;i++){
		check_value[i]=data[i];
	}
	do{
		if(check_value[0] == '1'){
			XOR();
		}
		for(j=0;j<N-1;j++){
			check_value[j]=check_value[j+1];
		}
		check_value[j]=data[i++];
	}while(i<=data_length+N-1);
}

int main(){
	printf("Enter data to be transmitted:");
	scanf("%s",data);
	printf("Enter the generating polynomial:");
	scanf("%s",gen_poly);
	data_length=strlen(data);
	for(i=data_length;i<data_length+N-1;i++){
		data[i]='0';
	}
	printf("\n______________________________");
	printf("\nData with N-1 zeros padded is : %s ",data);
	crc();
	printf("\n______________________________");
	printf("\n Check value is : %s",check_value);
	for(i=data_length;i<data_length+N-1;i++){
		data[i]=check_value[i-data_length];
	}
	printf("\n______________________________");
	printf("\n Final data to be sent is : %s",data);
	
	printf("\n Enter the recieved data:");
	scanf("%s",rdata);
	for(i=0;i<data_length+N;i++){
		if(rdata[i] != data[i]){
			printf("Error Detected.");
		}
		else{
			c++;
		}
	}
	if(c == data_length + N){
		printf("No ERROR");
	}
	
}







