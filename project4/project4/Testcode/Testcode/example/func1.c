int outprint(int* j){
    *j = *j + 10;
}

int main(){
	char b[10];
    char *a;
    int* i;
    *i = 10;
    b[0] = 'a';
    b[1] = 'b';
    b[2] = 'c';
    outprint(i);
    a = "car";
	write_string(b);
    write_string("\n");
	write_string(a);
    write_string("\n");
}
