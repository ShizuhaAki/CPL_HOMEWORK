#include <stdio.h>

int main()
{
    char sentence[4096];
    char c;

    // 读取输入的英文句子
    int index = 0;
    while ((c = getchar()) != '\n' && index < sizeof(sentence) - 1)
    {
        sentence[index++] = c;
    }
    sentence[index] = '\0';

    // 遍历句子，将每个单词的首字母大写，其他字母小写
    int capitalize = 0; // 表示下一个字母是否要大写
    printf("%c", (sentence[0] >= 'a' && sentence[0] <= 'z' ? sentence[0] - 'a' + 'A' : sentence[0]));
    for (int i = 1; i < index; i++)
    {
        if (sentence[i] == ' ')
        {
            capitalize = 1; // 下一个单词的首字母要大写
        }
        else
        {
            if (capitalize)
            {
                sentence[i] = (sentence[i] >= 'a' && sentence[i] <= 'z' ? sentence[i] - 'a' + 'A' : sentence[i]);
                capitalize = 0;
            }
            else
            {
                sentence[i] = (sentence[i] >= 'A' && sentence[i] <= 'Z' ? sentence[i] - 'A' + 'a' : sentence[i]);
            }
        }
        printf("%c", sentence[i]);
    }

    return 0;
}
