#include<iostream>
#include<fstream>
using namespace std;

int main(){
    FILE *fp;
    fp = fopen("sudu_rule.cnf","w+");
    fprintf(fp, "p cnf 1464 4760\n");
    //约束1
    //行
    for (int i = 0; i < 8; i++){
        for (int j = 1 + 8 * i; j < 7 + 8 * i; j++){
            fprintf(fp, "%d %d %d 0\n",j,j+1,j+2);
            fprintf(fp, "%d %d %d 0\n",-j,-j-1,-j-2);
        }
    }
    //列
    
    for (int i = 1; i < 9; i++){
        for (int j = i; j < i + 48; j=j+8){
            fprintf(fp, "%d %d %d 0\n",j,j+8,j+16);
            fprintf(fp, "%d %d %d 0\n",-j,-j-8,-j-16);
        }
    }
    //约束2
    for (int i = 1; i < 65;i+=8){
        fprintf(fp, "%d %d %d %d %d 0\n",i,i+1,i+2,i+3,i+4);
        fprintf(fp, "%d %d %d %d %d 0\n",-i,-i-1,-i-2,-i-3,-i-4);
    }
    for (int i = 1; i < 9;i++){
        fprintf(fp, "%d %d %d %d %d 0\n",i,i+8,i+16,i+24,i+32);
        fprintf(fp, "%d %d %d %d %d 0\n",-i,-i-8,-i-16,-i-24,-i-32);
    }
    //约束3
    int add;        //已有变元数
    int final;      //增添后变元数
    int num1, num2;     //行列转换后变元
    add = 64;
	//处理8行
	for (int i = 1; i <= 8; i++) {
		for (int j = i + 1; j <= 8; j++) {
			final = add + 25;           
			for(int k = 1; k <= 8; k++) {
				num1 = (i - 1) * 8 + k;
				num2 = (j - 1) * 8 + k;
                //先处理两行的单个变元，例如51和71
				fprintf(fp, "%d -%d 0\n%d -%d 0\n-%d -%d %d 0\n", num1, add + 1, num2, add + 1, num1, num2, add + 1);       //例如15710
				fprintf(fp, "-%d -%d 0\n-%d -%d 0\n%d %d %d 0\n", num1, add + 2, num2, add + 2, num1, num2, add + 2);       //例如15711
                //处理1578 = 15780&15781
				fprintf(fp, "-%d %d 0\n-%d %d 0\n%d %d -%d 0\n", add + 1, add + 3, add + 2, add + 3, add + 1, add + 2, add + 3);
				add += 3;
			}
            //处理157的后8个子句
			for (int z = 1; z <= 8; z++) {
				fprintf(fp, "%d %d 0\n", final - 3 * (z - 1) - 1, final);
			}
            //处理157的第一个子句
			fprintf(fp, "-%d -%d -%d -%d -%d -%d -%d -%d -%d 0\n", final - 22 ,final - 19, final - 16, final - 13, final - 10, final - 7, final - 4, final - 1, final);
			add = final;
		}
	}
	//处理8列
	for (int i = 1; i <= 8; i++) {
		for (int j = i + 1; j <= 8; j++) {
			final = add + 25;
			for (int k = 1; k <= 8; k++) {
				num1 = (k - 1) * 8 + i;
				num2 = (k - 1) * 8 + j;
				fprintf(fp, "%d -%d 0\n%d -%d 0\n-%d -%d %d 0\n", num1, add + 1, num2, add + 1, num1, num2, add + 1);
				fprintf(fp, "-%d -%d 0\n-%d -%d 0\n%d %d %d 0\n", num1, add + 2, num2, add + 2, num1, num2, add + 2);
				fprintf(fp, "-%d %d 0\n-%d %d 0\n%d %d -%d 0\n", add + 1, add + 3, add + 2, add + 3, add + 1, add + 2, add + 3);
				add += 3;
			}
			for (int z = 1; z <= 8; z++) {
				fprintf(fp, "%d %d 0\n", final - 3 * (z - 1) - 1, final);
			}
			fprintf(fp, "-%d -%d -%d -%d -%d -%d -%d -%d -%d 0\n", final - 22 ,final - 19, final - 16, final - 13, final - 10, final - 7, final - 4, final - 1, final);
			add = final;
		}
	}

    return 0;
}