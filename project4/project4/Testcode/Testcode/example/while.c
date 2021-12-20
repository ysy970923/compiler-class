int main(){
	int a;
    int i;
	a = 3;

    while(a > 0)
    {
        a = a-1;
        if (a == 0)
            break;
        a = a-1;
    }

    for (i=0; i < 10; i++)
    {
        write_int(i);
	    write_string("\n");
        if (i == 5)
            break;
    }
	write_int(a);
	write_string("\n");
}
