struct str1 {
    int x;
    int y;
};

struct str1 temp(struct str1 a)
{
    return a;
}

int main()
{
    struct str1 strstr1;
    struct str1 strstr2;
    strstr1.x = 10;
    strstr1.y = 20;
    strstr2 = temp(strstr1);
    write_int(strstr2.x);
    write_string("\n");
}