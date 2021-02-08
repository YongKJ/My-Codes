#include "stdafx.h"
using namespace std;
struct User {
  int ID;          //用户编号
  string Name;     //用户登录名
  string Password; //用户登录密码
  string realName; //真实姓名
};
struct BankCard {
  string ID;       //卡号
  string Password; //交易密码
  int userID;      //所属用户号
  string bankName; //银行名称 
  double Balance;  //余额
};
struct Trade {
  int ID;             //交易编号
  string cardID;      //交易卡号
  double tradeMoney; //交易金额
  string dateTime;    //交易时间
  string Type;        //交易类型，值仅为收入与支出
  string About;       //交易备注说明，允许为空
};
class personalFinance {
public:
  personalFinance();
  void display();          //显示数据(调试函数)
  void init();             //初始化用户、银行卡、交易数据
  void readInfoFromFile(); //从文件中读取用户、银行卡、交易信息
  void writeInfoToFile(); //将用户、银行卡、交易信息写入到文件中
  bool userLogin(User user); //用户登录
  bool userRegister(User user); //用户注册
  bool userModify(User user);//用户修改
  bool mainUIOperation(int chooseOperation, BankCard theBankCard,
                       Trade theTrade); //从主界面中选择要进行的操作
  bool addBankCard(BankCard theBankCard);    //添加银行卡
  bool findBankCard(BankCard theBankCard);   //查询银行卡
  bool changeBankCard(BankCard theBankCard); //修改银行卡信息
  bool addTrade(Trade theTrade);             //添加交易
  void getUsrBankCards(User user);           //获取当前用户的银行卡
  bool tradeManagementOperation(int chooseOperation, BankCard theBankCard,
                                Trade theTrade); //从交易管理中选择要进行的操作
  void getUsrBankCardTrades(BankCard theBankCard); //获取当前银行卡的交易记录
  bool theFirstTrade();                            //转到第一条交易
  bool nextTrade();                                //下一条交易
  bool upTrade();                                  //上一条交易
  bool theLastTrade();                             //转到最后一条交易
  bool updateUsrBankCardTrade(Trade theTrade);//修改当前交易信息
  void updateInformation();//更新当前用户信息、此刻银行卡信息
  User getUser();                                  //获取用户信息
  BankCard getUsrBankCard();     //获取当前用户使用的银行卡信息
  Trade getUsrBankCardTrade();   //获取当前交易信息
  int getUsrsSum();//获取用户信息记录表总数
  int getUsrBankCardTradesSum(); //获取当前交易信息表中的交易总数
  int getTrades();//获取交易信息记录表中的交易总数
  bool saveUsrNameAndPassword(User user);//保存当前用户的登录名和密码（注册用）

private:
  int tradeNumber;              //记录当前第几条交易记录
  User usr;                     //当前使用个人理财系统的用户
  BankCard usrBankCard;         //当前用户使用的银行卡
  Trade usrBankCardTrade;       //当前用户所使用银行卡的当前交易
  map<int, User> usrs;          //用户信息记录表
  map<int, BankCard> bankCards; //银行卡信息记录表
  map<int, Trade> trades;       //交易信息记录表
  map<int, BankCard> usrBankCards;   //当前用户银行卡信息记录表
  map<int, Trade> usrBankCardTrades; //当前银行卡的交易信息记录表
};
