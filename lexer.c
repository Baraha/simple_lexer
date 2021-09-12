#include <stdio.h>
#include <string.h>

struct TokenType {
    char name [20];   
};

struct Position {int x,y;};
struct Token {
    struct Position Pos;
    char type[12];
    char text;
    struct Token *link;
};



void lexerConvert(char word[]){
	const char TEMP_OP_TYPE[][12] = {"PLUS","MINUS","CLOSE", "PRINT"};
	const char TEMP_OP_VAR[10] = {'1','2','3','4','5','6','7','8','9','0'};
	int flag_op = 0;
	for(int op_item=0;op_item<sizeof(TEMP_OP_TYPE);++op_item){
		for(int cnt_op = 0; cnt_op< sizeof(TEMP_OP_TYPE[op_item]); ++cnt_op){
			printf("scann word and  op_item {%c} :  %c \n",TEMP_OP_TYPE[op_item][cnt_op], word[cnt_op]);
			if(word[op_item] != TEMP_OP_TYPE[op_item][cnt_op]){
				flag_op = 1;
				break;	
			}
		};
		
		printf("word is  operator?, op_item {%s} :  %s \n",TEMP_OP_TYPE[op_item], word);
		if(word==TEMP_OP_TYPE[op_item]){
			printf("word is operator! : %s \n", word);
		}
	};

       		

}


void catchWord(char buffer[]){
	char word[127];
	int cnt_in_word = 0;
	for( int cnt=0; cnt<127; cnt++ ){
		//printf("%c ", buffer[cnt]);
		if(buffer[cnt] != ' '){
			word[cnt_in_word] = buffer[cnt];
			printf("%c - word, %c - buffer \n", word[cnt_in_word],buffer[cnt]);
			cnt_in_word++;

		}else if(buffer[cnt]==' '){
			cnt_in_word = 0;
			lexerConvert(word);
			printf("word is %s \n", word);
			for(int i = 0; i < sizeof(word); ++i)
			{
				  word[i] = (char)0;
			}  
			
		}

	};     
}

void fileRead(){
	char buffer[128];
	FILE *fp;
	char name[] = "my.convert";
	if ((fp = fopen(name, "r")) == NULL){
		printf("Не удалось открыть файл");
	}
	fgets(buffer, 127, fp);
	fclose(fp);
	catchWord(buffer);
}


int main(){
	fileRead();
	struct Token start;
    	struct Token tok;
    	char valueType [][12] = {"string","int"};
    	start.link = &tok;
    	//00printf("start: %s \n",valueType);
    	return 0;
}
