#include <iostream>
#include <string>
using namespace std;
inline int compare(string str1,string str2) {//��ȷ���0�����ڷ���1��С�ڷ���-1
         if (str1.size()>str2.size()) return 1; //���ȳ����������ڳ���С������
    else if (str1.size()<str2.size()) return -1;
    else                              return str1.compare(str2); //��������ȣ���ͷ��β��λ�Ƚ�
}
string SUB_INT(string str1,string str2);
string ADD_INT(string str1,string str2) {//�߾��ȼӷ�
    int sign=1; //sign Ϊ����λ
    string str;
    if (str1[0]=='-') {
        if (str2[0]=='-') {
            sign=-1;
            str=ADD_INT(str1.erase(0,1),str2.erase(0,1));
        } else {
            str=SUB_INT(str2,str1.erase(0,1));
        }
    } else {
        if (str2[0]=='-') {
            str=SUB_INT(str1,str2.erase(0,1));
        } else { //�������������룬������ǰ���0����
            string::size_type L1,L2;
            int i;
            L1=str1.size();
            L2=str2.size();
            if (L1<L2) {
                for (i=1;i<=L2-L1;i++) str1="0"+str1;
            } else {
                for (i=1;i<=L1-L2;i++) str2="0"+str2;
            }
            int int1=0,int2=0; //int2 ��¼��λ
            for (i=str1.size()-1;i>=0;i--) {
                int1=(int(str1[i])-'0'+int(str2[i])-'0'+int2)%10;
                int2=(int(str1[i])-'0'+int(str2[i])-'0'+int2)/10;
                str=char(int1+'0')+str;
            }
            if (int2!=0) str=char(int2+'0')+str;
        }
    }
    //����������λ
    if ((sign==-1)&&(str[0]!='0')) str="-"+str;
    return str;
}
string SUB_INT(string str1,string str2) {//�߾��ȼ���
    int sign=1; //sign Ϊ����λ
    string str;
    int i,j;
    if (str2[0]=='-') {
        str=ADD_INT(str1,str2.erase(0,1));
    } else {
        int res=compare(str1,str2);
        if (res==0) return "0";
        if (res<0) {
            sign=-1;
            string temp =str1;
            str1=str2;
            str2=temp;
        }
        string::size_type tempint;
        tempint=str1.size()-str2.size();
        for (i=str2.size()-1;i>=0;i--) {
            if (str1[i+tempint]<str2[i]) {
                j=1;
                while (1) {//zhao4zhong1���
                    if (str1[i+tempint-j]=='0') {
                        str1[i+tempint-j]='9';
                        j++;
                    } else {
                        str1[i+tempint-j]=char(int(str1[i+tempint-j])-1);
                        break;
                    }
                }
                str=char(str1[i+tempint]-str2[i]+':')+str;
            } else {
                str=char(str1[i+tempint]-str2[i]+'0')+str;
            }
        }
        for (i=tempint-1;i>=0;i--) str=str1[i]+str;
    }
    //ȥ������ж����ǰ��0
    str.erase(0,str.find_first_not_of('0'));
    if (str.empty()) str="0";
    if ((sign==-1) && (str[0]!='0')) str ="-"+str;
    return str;
}
string MUL_INT(string str1,string str2) {//�߾��ȳ˷�
    int sign=1; //sign Ϊ����λ
    string str;
    if (str1[0]=='-') {
        sign*=-1;
        str1 =str1.erase(0,1);
    }
    if (str2[0]=='-') {
        sign*=-1;
        str2 =str2.erase(0,1);
    }
    int i,j;
    string::size_type L1,L2;
    L1=str1.size();
    L2=str2.size();
    for (i=L2-1;i>=0;i--) { //ģ���ֹ��˷���ʽ
        string tempstr;
        int int1=0,int2=0,int3=int(str2[i])-'0';
        if (int3!=0) {
            for (j=1;j<=(int)(L2-1-i);j++) tempstr="0"+tempstr;
            for (j=L1-1;j>=0;j--) {
                int1=(int3*(int(str1[j])-'0')+int2)%10;
                int2=(int3*(int(str1[j])-'0')+int2)/10;
                tempstr=char(int1+'0')+tempstr;
            }
            if (int2!=0) tempstr=char(int2+'0')+tempstr;
        }
        str=ADD_INT(str,tempstr);
    }
    //ȥ������е�ǰ��0
    str.erase(0,str.find_first_not_of('0'));
    if (str.empty()) str="0";
    if ((sign==-1) && (str[0]!='0')) str="-"+str;
    return str;
}
string DIVIDE_INT(string str1,string str2,int flag) {//�߾��ȳ�����flag==1ʱ,������; flag==0ʱ,��������
    string quotient,residue; //�����̺�����
    int sign1=1,sign2=1;
    if (str2 == "0") {  //�жϳ����Ƿ�Ϊ0
        quotient= "ERROR!";
        residue = "ERROR!";
        if (flag==1) return quotient;
        else         return residue ;
    }
    if (str1=="0") { //�жϱ������Ƿ�Ϊ0
        quotient="0";
        residue ="0";
    }
    if (str1[0]=='-') {
        str1   = str1.erase(0,1);
        sign1 *= -1;
        sign2  = -1;
    }
    if (str2[0]=='-') {
        str2   = str2.erase(0,1);
        sign1 *= -1;
    }
    int res=compare(str1,str2);
    if (res<0) {
        quotient="0";
        residue =str1;
    } else if (res == 0) {
        quotient="1";
        residue ="0";
    } else {
        string::size_type L1,L2;
        L1=str1.size();
        L2=str2.size();
        string tempstr;
        tempstr.append(str1,0,L2-1);
        for (int i=L2-1;i<L1;i++) { //ģ���ֹ�������ʽ
            tempstr=tempstr+str1[i];
            tempstr.erase(0,tempstr.find_first_not_of('0'));//zhao4zhong1���
            if (tempstr.empty()) tempstr="0";//zhao4zhong1���
            for (char ch='9';ch>='0';ch--) { //����
                string str;
                str=str+ch;
                if (compare(MUL_INT(str2,str),tempstr)<=0) {
                    quotient=quotient+ch;
                    tempstr =SUB_INT(tempstr,MUL_INT(str2,str));
                    break;
                }
            }
        }
        residue=tempstr;
    }
    //ȥ������е�ǰ��0
    quotient.erase(0,quotient.find_first_not_of('0'));
    if (quotient.empty()) quotient="0";
    if ((sign1==-1)&&(quotient[0]!='0')) quotient="-"+quotient;
    if ((sign2==-1)&&(residue [0]!='0')) residue ="-"+residue ;
    if (flag==1) return quotient;
    else         return residue ;
}
string DIV_INT(string str1,string str2) {//�߾��ȳ���,������
    return DIVIDE_INT(str1,str2,1);
}
string MOD_INT(string str1,string str2) {//�߾��ȳ���,��������
    return DIVIDE_INT(str1,str2,0);
}
int main() {
    char ch;
    string s1,s2,res;
	cin>>s1>>s2;
    res=DIV_INT(s1,s2);
    cout<<res<<endl;
    return 0;
}
