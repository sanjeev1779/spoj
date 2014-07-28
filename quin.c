#include <stdio.h>

  const char *data[] = {
    "  NULL};",
    "",
    "void print_string(const char *str)",
    "{",
    "  const char *ptr;",
    "  printf(\"  \\\"\");",
    "  for (ptr = str; *ptr != 0; ptr++)",
    "  if (*ptr == '\\\\')",
    "  printf(\"\\\\\\\\\");",
    "  else if (*ptr == '\"')",
    "  printf(\"\\\\\\\"\");",
    "  else",
    "  putchar(*ptr); ",
    "  printf(\"\\\",\\n\");",
    "}",
    "",
    "int main()",
    "{",
    "  int N,i=2,d=0;",
    "  scanf(\"%d\",&N);",
    "  for(;i<N;i++)",
    "{",
    "  if(!(N%i))",
    "{",
    "  d=1;break;",
    "}",
    "}",
    "  if(!d&&N!=1)printf(\"YES\");",
    "  else",
    "{",
    "  const char **ptr;",
    "  printf(\"#include <stdio.h>\\n\\n\");",
    "  printf(\"const char *data[] = {\\n\");",
    "  for (ptr = data; *ptr != NULL; ptr++)",
    "  print_string(*ptr);",
    "  for (ptr = data; *ptr != NULL; ptr++)",
    "  printf(\"%s\\n\", *ptr);",
    "}",
    "  return 0;",
    "}",
    NULL};

  void print_string(const char *str)
  {
    const char *ptr;
    printf("  \"");
    for (ptr = str; *ptr != 0; ptr++)
    if (*ptr == '\\')
    printf("\\\\");
    else if (*ptr == '"')
    printf("\\\"");
    else
    putchar(*ptr);
    printf("\",\n");
  }

  int main()
  {
    int N,i=2,d=0;
    scanf("%d",&N);
    for(;i<N;i++)
  {
    if(!(N%i))
  {
    d=1;break;
  }
  }
    if(!d&&N!=1)printf("YES");
    else
  {
    const char **ptr;
    printf("#include <stdio.h>\n\n");
    printf("const char *data[] = {\n");
    for (ptr = data; *ptr != NULL; ptr++)
    print_string(*ptr);
    for (ptr = data; *ptr != NULL; ptr++)
    printf("%s\n", *ptr);
  }
    return 0;
  }
