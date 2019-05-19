#include"CommentConvert.h"
//未知状态处理
void DoNulState(FILE *pfin, FILE *pfout, enum State *ps)
{
	int first = fgetc(pfin);   //从文件中读取一个字符
	int second;
	switch (first)
	{
	case '/':                  //如果这个字符是'/',则证明有可能是c状态(/**/),也有可能是c++状态(//),则需要读下一个字符
		   second = fgetc(pfin);
		   switch (second)						//从文件中读取下一个字符
		  {	
	     	case '/':							//如果是‘/',则在output里原样输出，并将状态切换到c++状态
				fputc(first, pfout);
				fputc(second, pfout);
				*ps = CPP_STATE;
				break;
			case '*':							 //如果是‘*',则在output里写入两个'/'，并将状态切换到c状态
				fputc('/', pfout);
				fputc('/', pfout);
				*ps = C_STATE;
				break;
			//default:							 //如果是其他字符，则原样输出
			//	fputc(first, pfout);
			//	fputc(second, pfout);
			//	break;
			}
	break;
	case EOF:
		*ps = END_STATE;      //如果读到文件结束标志，则将状态改为结束状态。
		break;
	default: fputc(first, pfout); //如果读到其他字符，则原样输出。
		break;
	}
}
//cpp状态处理 (//)
void DoCPPState(FILE *pfin, FILE *pfout, enum State *ps)
{
	int first = fgetc(pfin);  //从文件中读取第一个字符
	switch (first)
	{
	case EOF:				 //如果读到EOF，则将状态装换为结束状态          
		*ps = END_STATE;
		 break; 
	case '\n':               //如果读到'\n'，则打印一个换行符并将状态转换为未知状态
		fputc('\n', pfout);
		*ps = NUL_STATE;
		break;
	default:                 //如果读到其他字符，则原样输出
		fputc(first, pfout);
		break;
	}
}
//c状态处理
void DoCState(FILE *pfin, FILE *pfout, enum State *ps)
{
	int first = fgetc(pfin); //读取一个字符
	int second;
	int third;
	int fourth;
	switch (first)
	{
	case '*': //如果读取的字符是’*’，则需要判断下一个字符是什么
			second = fgetc(pfin);
			switch (second)
			{
			case '/':					//如果是'/',则证明注释已经完成，但仍需要判断，这一行有没有字符
					third = fgetc(pfin);
					switch (third)
					{
					case '/':									//如果是‘/',则有可能为c或者c++状态。继续判断下一个
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
					case '\n':									//如果是’\n',则打印\n并切换到未知状态
						fputc('\n', pfout);
						*ps = NUL_STATE;
						break;
					default:									 //如果是其他字符，则打印一个换行符，切换至未知状态
						fputc('\n', pfout);
						*ps = NUL_STATE;
						break;
					}
			 break;
			 case '*':						//如果*后面还有*，则将读取的第一个*写入pfout,第二个*送回pfin
				ungetc(second, pfin);
				fputc(first, pfout);
				break;
			 default:						//如果*后面是其他字符，则原样输出
				 fputc(first, pfout);
				 fputc(second, pfout);
				 break;
			}
	break;
	case '\n':   //如果读到回车，则添加换行，以及两个//
		fputc('\n', pfout);
		fputc('/', pfout);
		fputc('/', pfout);
		break;
	default:           //其他字符原样输出
		 fputc(first, pfout);
		break;
	}
}
/*
**注释转换函数
*/
void DoCommentConvert(FILE *pfin, FILE * pfout)
{
	enum State state = NUL_STATE; //刚开始什么都没有读，处于未知状态
	while (state != END_STATE)
	{
		switch (state)
		{
		case NUL_STATE: //由于在处理这种状态的内部，有可能再次发生状态转变，作用状态转变应该传地址
			DoNulState(pfin, pfout,&state);  //处理未知状态
			break;
		case C_STATE:  DoCState(pfin, pfout, &state);
			break;
		case CPP_STATE:  DoCPPState(pfin, pfout, &state);
			break;
		}
	}

}