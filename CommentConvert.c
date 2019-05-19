#include"CommentConvert.h"
//δ֪״̬����
void DoNulState(FILE *pfin, FILE *pfout, enum State *ps)
{
	int first = fgetc(pfin);   //���ļ��ж�ȡһ���ַ�
	int second;
	switch (first)
	{
	case '/':                  //�������ַ���'/',��֤���п�����c״̬(/**/),Ҳ�п�����c++״̬(//),����Ҫ����һ���ַ�
		   second = fgetc(pfin);
		   switch (second)						//���ļ��ж�ȡ��һ���ַ�
		  {	
	     	case '/':							//����ǡ�/',����output��ԭ�����������״̬�л���c++״̬
				fputc(first, pfout);
				fputc(second, pfout);
				*ps = CPP_STATE;
				break;
			case '*':							 //����ǡ�*',����output��д������'/'������״̬�л���c״̬
				fputc('/', pfout);
				fputc('/', pfout);
				*ps = C_STATE;
				break;
			//default:							 //����������ַ�����ԭ�����
			//	fputc(first, pfout);
			//	fputc(second, pfout);
			//	break;
			}
	break;
	case EOF:
		*ps = END_STATE;      //��������ļ�������־����״̬��Ϊ����״̬��
		break;
	default: fputc(first, pfout); //������������ַ�����ԭ�������
		break;
	}
}
//cpp״̬���� (//)
void DoCPPState(FILE *pfin, FILE *pfout, enum State *ps)
{
	int first = fgetc(pfin);  //���ļ��ж�ȡ��һ���ַ�
	switch (first)
	{
	case EOF:				 //�������EOF����״̬װ��Ϊ����״̬          
		*ps = END_STATE;
		 break; 
	case '\n':               //�������'\n'�����ӡһ�����з�����״̬ת��Ϊδ֪״̬
		fputc('\n', pfout);
		*ps = NUL_STATE;
		break;
	default:                 //������������ַ�����ԭ�����
		fputc(first, pfout);
		break;
	}
}
//c״̬����
void DoCState(FILE *pfin, FILE *pfout, enum State *ps)
{
	int first = fgetc(pfin); //��ȡһ���ַ�
	int second;
	int third;
	int fourth;
	switch (first)
	{
	case '*': //�����ȡ���ַ��ǡ�*��������Ҫ�ж���һ���ַ���ʲô
			second = fgetc(pfin);
			switch (second)
			{
			case '/':					//�����'/',��֤��ע���Ѿ���ɣ�������Ҫ�жϣ���һ����û���ַ�
					third = fgetc(pfin);
					switch (third)
					{
					case '/':									//����ǡ�/',���п���Ϊc����c++״̬�������ж���һ��
						fourth = fgetc(pfin);
								switch (fourth)
								{
								case '*':
									fputc('/', pfout);
									fputc('/', pfout);
									*ps = C_STATE;
									break;
								case '/':
									fputc(third, pfout);
									fputc(fourth, pfout);
									*ps = CPP_STATE;
									break;
								}
					break;
					case '\n':									//����ǡ�\n',���ӡ\n���л���δ֪״̬
						fputc('\n', pfout);
						*ps = NUL_STATE;
						break;
					default:									 //����������ַ������ӡһ�����з����л���δ֪״̬
						fputc('\n', pfout);
						*ps = NUL_STATE;
						break;
					}
			 break;
			 case '*':						//���*���滹��*���򽫶�ȡ�ĵ�һ��*д��pfout,�ڶ���*�ͻ�pfin
				ungetc(second, pfin);
				fputc(first, pfout);
				break;
			 default:						//���*�����������ַ�����ԭ�����
				 fputc(first, pfout);
				 fputc(second, pfout);
				 break;
			}
	break;
	case '\n':   //��������س�������ӻ��У��Լ�����//
		fputc('\n', pfout);
		fputc('/', pfout);
		fputc('/', pfout);
		break;
	default:           //�����ַ�ԭ�����
		 fputc(first, pfout);
		break;
	}
}
/*
**ע��ת������
*/
void DoCommentConvert(FILE *pfin, FILE * pfout)
{
	enum State state = NUL_STATE; //�տ�ʼʲô��û�ж�������δ֪״̬
	while (state != END_STATE)
	{
		switch (state)
		{
		case NUL_STATE: //�����ڴ�������״̬���ڲ����п����ٴη���״̬ת�䣬����״̬ת��Ӧ�ô���ַ
			DoNulState(pfin, pfout,&state);  //����δ֪״̬
			break;
		case C_STATE:  DoCState(pfin, pfout, &state);
			break;
		case CPP_STATE:  DoCPPState(pfin, pfout, &state);
			break;
		}
	}

}