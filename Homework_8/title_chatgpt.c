#include <stdio.h>

int main()
{
    char sentence[4096];
    char c;

    // ��ȡ�����Ӣ�ľ���
    int index = 0;
    while ((c = getchar()) != '\n' && index < sizeof(sentence) - 1)
    {
        sentence[index++] = c;
    }
    sentence[index] = '\0';

    // �������ӣ���ÿ�����ʵ�����ĸ��д��������ĸСд
    int capitalize = 0; // ��ʾ��һ����ĸ�Ƿ�Ҫ��д
    printf("%c", (sentence[0] >= 'a' && sentence[0] <= 'z' ? sentence[0] - 'a' + 'A' : sentence[0]));
    for (int i = 1; i < index; i++)
    {
        if (sentence[i] == ' ')
        {
            capitalize = 1; // ��һ�����ʵ�����ĸҪ��д
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
