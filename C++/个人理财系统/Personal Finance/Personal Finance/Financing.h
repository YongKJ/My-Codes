#include "stdafx.h"
using namespace std;
struct User {
  int ID;          //�û����
  string Name;     //�û���¼��
  string Password; //�û���¼����
  string realName; //��ʵ����
};
struct BankCard {
  string ID;       //����
  string Password; //��������
  int userID;      //�����û���
  string bankName; //�������� 
  double Balance;  //���
};
struct Trade {
  int ID;             //���ױ��
  string cardID;      //���׿���
  double tradeMoney; //���׽��
  string dateTime;    //����ʱ��
  string Type;        //�������ͣ�ֵ��Ϊ������֧��
  string About;       //���ױ�ע˵��������Ϊ��
};
class personalFinance {
public:
  personalFinance();
  void display();          //��ʾ����(���Ժ���)
  void init();             //��ʼ���û������п�����������
  void readInfoFromFile(); //���ļ��ж�ȡ�û������п���������Ϣ
  void writeInfoToFile(); //���û������п���������Ϣд�뵽�ļ���
  bool userLogin(User user); //�û���¼
  bool userRegister(User user); //�û�ע��
  bool userModify(User user);//�û��޸�
  bool mainUIOperation(int chooseOperation, BankCard theBankCard,
                       Trade theTrade); //����������ѡ��Ҫ���еĲ���
  bool addBankCard(BankCard theBankCard);    //������п�
  bool findBankCard(BankCard theBankCard);   //��ѯ���п�
  bool changeBankCard(BankCard theBankCard); //�޸����п���Ϣ
  bool addTrade(Trade theTrade);             //��ӽ���
  void getUsrBankCards(User user);           //��ȡ��ǰ�û������п�
  bool tradeManagementOperation(int chooseOperation, BankCard theBankCard,
                                Trade theTrade); //�ӽ��׹�����ѡ��Ҫ���еĲ���
  void getUsrBankCardTrades(BankCard theBankCard); //��ȡ��ǰ���п��Ľ��׼�¼
  bool theFirstTrade();                            //ת����һ������
  bool nextTrade();                                //��һ������
  bool upTrade();                                  //��һ������
  bool theLastTrade();                             //ת�����һ������
  bool updateUsrBankCardTrade(Trade theTrade);//�޸ĵ�ǰ������Ϣ
  void updateInformation();//���µ�ǰ�û���Ϣ���˿����п���Ϣ
  User getUser();                                  //��ȡ�û���Ϣ
  BankCard getUsrBankCard();     //��ȡ��ǰ�û�ʹ�õ����п���Ϣ
  Trade getUsrBankCardTrade();   //��ȡ��ǰ������Ϣ
  int getUsrsSum();//��ȡ�û���Ϣ��¼������
  int getUsrBankCardTradesSum(); //��ȡ��ǰ������Ϣ���еĽ�������
  int getTrades();//��ȡ������Ϣ��¼���еĽ�������
  bool saveUsrNameAndPassword(User user);//���浱ǰ�û��ĵ�¼�������루ע���ã�

private:
  int tradeNumber;              //��¼��ǰ�ڼ������׼�¼
  User usr;                     //��ǰʹ�ø������ϵͳ���û�
  BankCard usrBankCard;         //��ǰ�û�ʹ�õ����п�
  Trade usrBankCardTrade;       //��ǰ�û���ʹ�����п��ĵ�ǰ����
  map<int, User> usrs;          //�û���Ϣ��¼��
  map<int, BankCard> bankCards; //���п���Ϣ��¼��
  map<int, Trade> trades;       //������Ϣ��¼��
  map<int, BankCard> usrBankCards;   //��ǰ�û����п���Ϣ��¼��
  map<int, Trade> usrBankCardTrades; //��ǰ���п��Ľ�����Ϣ��¼��
};
