int global_1;
int global_2;

struct _str1{
	int x;
	int y;
	struct _st2{
		int z;
		int w[5];
	}strstr;
}sample_str;

int main(){
	int i;
	int j;
	int k;
	int *l;
    struct _str1 *str;
	struct _str1 teststr[10];

	i = 5;

    str = &(teststr[i]);
	str->strstr.w[3] = 20;

	j = teststr[i].strstr.w[3];
	write_int(j);
	write_string("\n");
}
