#include "stdafx.h"
/*int main() {
  personalFinance a;
  a.display();
  return 0;
}*/
void personalFinance::display(){//��ʾ����(���Ժ���)
  for (int i = 0; i < int(usrs.size()); i++) {
    cout << usrs[i].ID << " ";
    cout << usrs[i].Name << " ";
    cout << usrs[i].Password << " ";
    cout << usrs[i].realName << endl;
  }
  for (int i = 0; i < int(bankCards.size()); i++) {
    cout << bankCards[i].ID << " ";
    cout << bankCards[i].Password << " ";
    cout << bankCards[i].userID << " ";
    cout << bankCards[i].bankName << " ";
    cout << bankCards[i].Balance << endl;
  }
  for (int i = 0; i < int(trades.size()); i++) {
    cout << trades[i].ID << " ";
    cout << trades[i].cardID << " ";
    cout << trades[i].tradeMoney << " ";
    cout << trades[i].dateTime << " ";
    cout << trades[i].Type << " ";
    cout << trades[i].About << endl;
  }
}
personalFinance::personalFinance() { 
	readInfoFromFile();
	//writeInfoToFile();
}
void personalFinance::init() { //��ʼ���û������п�����������
  User user;
  BankCard userBankCard;
  Trade trade;
  user.ID = 1;
  user.Name = "zs";
  user.Password = "123";
  user.realName = "����";
  usrs[0] = user;
  user.ID = 2;
  user.Name = "ls";
  user.Password = "1234";
  user.realName = "����";
  usrs[1] = user;
  userBankCard.ID = "333";
  userBankCard.Password = "123";
  userBankCard.userID = 1;
  userBankCard.bankName = "�й�����";
  userBankCard.Balance = 100;
  bankCards[0] = userBankCard;
  trade.ID=1;
  trade.cardID="333";
  trade.tradeMoney=11;
  trade.dateTime="2019-04-27 08:03:41";
  trade.Type="֧��";
  trade.About="�Է�";
  trades[0]=trade;
  trade.ID=2;
  trade.cardID="333";
  trade.tradeMoney=8;
  trade.dateTime="2019-04-27 08:03:51";
  trade.Type="����";
  trade.About="��";
  trades[1]=trade;

}
void personalFinance::readInfoFromFile() {//���ļ��ж�ȡ�û������п���������Ϣ
  usrs.clear();
  bankCards.clear();
  trades.clear();
  User user;
  BankCard userBankCard;
  Trade userBankCardTrade;
  string strDateTime;
  ifstream usersData("usersData.txt");
  ifstream bankCardsData("bankCardsData.txt");
  ifstream tradesData("tradesData.txt");
  if (!usersData || !bankCardsData || !tradesData) {
    init();
    return;
  } 
  for (int i = 0; usersData >> user.ID; i++) {
    usersData >> user.Name;
    usersData >> user.Password;
    usersData >> user.realName;
    usrs[i] = user;
  }
  for (int i = 0; bankCardsData >> userBankCard.ID; i++) {
    bankCardsData >> userBankCard.Password;
    bankCardsData >> userBankCard.userID;
    bankCardsData >> userBankCard.bankName;
    bankCardsData >> userBankCard.Balance; 
    bankCards[i] = userBankCard;
  }
  for (int i = 0; tradesData >> userBankCardTrade.ID; i++) {
    tradesData >> userBankCardTrade.cardID;
    tradesData >> userBankCardTrade.tradeMoney;
    tradesData >> userBankCardTrade.dateTime;
    tradesData >> strDateTime;
    userBankCardTrade.dateTime += ' ' + strDateTime;
    tradesData >> userBankCardTrade.Type;
    tradesData >> userBankCardTrade.About;
    trades[i] = userBankCardTrade;
  }
  usersData.close();
  bankCardsData.close();
  tradesData.close();
}
void personalFinance::writeInfoToFile(){//���û������п���������Ϣд�뵽�ļ���
  ofstream usersData("usersData.txt");
  ofstream bankCardsData("bankCardsData.txt");
  ofstream tradesData("tradesData.txt");
  if(!usersData||!bankCardsData||!tradesData)
    return;
  for (int i = 0; i < int(usrs.size()); i++) {
    usersData << usrs[i].ID << " ";
    usersData << usrs[i].Name << " ";
    usersData << usrs[i].Password << " ";
    usersData << usrs[i].realName << endl;
  }
  for (int i = 0; i < int(bankCards.size()); i++) {
    bankCardsData << bankCards[i].ID << " ";
    bankCardsData << bankCards[i].Password << " ";
    bankCardsData << bankCards[i].userID << " ";
    bankCardsData << bankCards[i].bankName << " ";
    bankCardsData << bankCards[i].Balance << endl;
  }
  for (int i = 0; i < int(trades.size()); i++) {
    tradesData << trades[i].ID << " ";
    tradesData << trades[i].cardID << " ";
    tradesData << trades[i].tradeMoney << " ";
    tradesData << trades[i].dateTime << " ";
    tradesData << trades[i].Type << " ";
    tradesData << trades[i].About << endl;
  }
  usersData.close();
  bankCardsData.close();
  tradesData.close();
}
bool personalFinance::userLogin(User user){//�û���¼
  for(int i=0;i<int(usrs.size());i++){
    if (user.Name == usrs[i].Name && user.Password == usrs[i].Password) {
      usr = usrs[i];
      getUsrBankCards(usr);
      return true;
    }
  }
  return false;
}
bool personalFinance::saveUsrNameAndPassword(User user){//���浱ǰ�û��ĵ�¼�������루ע���ã�
	for(int i=0;i<int(usrs.size());i++){
		if(usrs[i].Name==user.Name){
			return false;
		}
	}
	usr=user;
	return true;
}
bool personalFinance::userRegister(User user){//�û�ע��
 //readInfoFromFile();
 for(int i=0;i<int(usrs.size());i++){
   if (user.Name == usrs[i].Name) {
     return false;
   }
 }
   usrs[usrs.size()] = user;
   writeInfoToFile();
   usr = user;
   getUsrBankCards(usr);
   return true;
}
bool personalFinance::mainUIOperation(int chooseOperation,BankCard theBankCard,Trade theTrade){//����������ѡ��Ҫ���еĲ���
  switch (chooseOperation) {
  case 1:
    return addBankCard(theBankCard);
    break;
  case 2:
    return findBankCard(theBankCard);
    break;
  case 3:
    return changeBankCard(theBankCard);
    break;
  case 4:
    return addTrade(theTrade);
    break;
  default:
    return false;
  }
}
bool personalFinance::addTrade(Trade theTrade){//��ӽ���
  if (theTrade.tradeMoney<0||(theTrade.tradeMoney > usrBankCard.Balance && theTrade.Type == "֧��")) {
    return false;
  }
  if (theTrade.Type == "����") {
    usrBankCard.Balance += theTrade.tradeMoney;
  } else {
    usrBankCard.Balance -= theTrade.tradeMoney;
  }
  trades[trades.size()] = theTrade;
  changeBankCard(usrBankCard);
  usrBankCardTrades[usrBankCardTrades.size()] = theTrade;
  return true;
}
bool personalFinance::changeBankCard(BankCard theBankCard){//�޸����п���Ϣ
  for(int i=0;i<int(bankCards.size());i++){
    if (bankCards[i].ID == theBankCard.ID) {
      bankCards[i] = theBankCard;
      writeInfoToFile();
      usrBankCard = theBankCard;
      getUsrBankCards(usr);
      return true;
    }
  }
  return false;
}
bool personalFinance::findBankCard(BankCard theBankCard){//��ѯ���п�
  for(int i=0;i<int(usrBankCards.size());i++){
    if (usrBankCards[i].ID == theBankCard.ID &&
        usrBankCards[i].Password == theBankCard.Password) {
      usrBankCard = usrBankCards[i];
      getUsrBankCardTrades(usrBankCard);
      return true;
    }
  }
  return false;
}
bool personalFinance::addBankCard(BankCard theBankCard){//������п�
  for(int i=0;i<int(bankCards.size());i++){
    if (bankCards[i].ID == theBankCard.ID) {
      return false;
    }
  }
  bankCards[bankCards.size()] = theBankCard;
  writeInfoToFile();
  usrBankCards[usrBankCards.size()]=theBankCard;
  usrBankCard = theBankCard;
  getUsrBankCardTrades(usrBankCard);
  return true;
}
bool personalFinance::tradeManagementOperation(int chooseOperation,BankCard theBankCard,Trade theTrade){//�ӽ��׹�����ѡ��Ҫ���еĲ���
  if(usrBankCardTrades.size()==0)
	getUsrBankCardTrades(theBankCard);
  switch (chooseOperation) {
  case 1:
    return theFirstTrade();
    break;
  case 2:
    return nextTrade();
    break;
  case 3:
    return upTrade();
    break;
  case 4:
    return theLastTrade();
    break;
  case 5:
    return updateUsrBankCardTrade(theTrade);
    break;
  default:
    return false;
  }
}
bool personalFinance::updateUsrBankCardTrade(Trade theTrade){//�޸ĵ�ǰ������Ϣ
	double theBalance;
	if(usrBankCardTrade.Type=="����"){
		theBalance=usrBankCard.Balance-usrBankCardTrade.tradeMoney;
	}else{
		theBalance=usrBankCard.Balance+usrBankCardTrade.tradeMoney;
	}
	if (theTrade.tradeMoney<0||(theTrade.Type == "֧��"&&theTrade.tradeMoney > theBalance )) {
    return false;
    }
    if (theTrade.Type == "����") {
    usrBankCard.Balance = theBalance+theTrade.tradeMoney;
    } else {
    usrBankCard.Balance = theBalance-theTrade.tradeMoney;
    }
    for(int i=0;i<int(trades.size());i++){
	    if(trades[i].ID==theTrade.ID){
		    trades[i]=theTrade;
		    break;
	    }
    }
	for(int i=0;i<int(bankCards.size());i++){
      if (bankCards[i].ID == usrBankCard.ID) {
        bankCards[i] = usrBankCard;
        break;
      }
    }
    //changeBankCard(usrBankCard);
    writeInfoToFile();
    usrBankCardTrade=theTrade;
    getUsrBankCards(usr);
	for(int i=0;i<int(usrBankCardTrades.size());i++){
		if(usrBankCardTrades[i].ID==theTrade.ID){
		    usrBankCardTrades[i]=theTrade;
		    break;
	    }
	}
    //getUsrBankCardTrades(usrBankCard);
    return true;
}
bool personalFinance::upTrade(){//��һ������
  if (tradeNumber - 2 >= 0) {
    tradeNumber -= 2;
    usrBankCardTrade = usrBankCardTrades[tradeNumber++];
    return true;
  }
  return false;
}
bool personalFinance::nextTrade(){//��һ������
  if (tradeNumber < int(usrBankCardTrades.size())) {
    usrBankCardTrade = usrBankCardTrades[tradeNumber++];
    return true;
  }
  return false;
}
bool personalFinance::theLastTrade(){//ת�����һ������
  if (usrBankCardTrades.size() != 0) {
    tradeNumber = usrBankCardTrades.size()-1;
    usrBankCardTrade = usrBankCardTrades[tradeNumber++];
    return true;
  }
  return false;
}
bool personalFinance::theFirstTrade(){//ת����һ������
  if (usrBankCardTrades.size() != 0) {
    tradeNumber = 0;
    usrBankCardTrade = usrBankCardTrades[tradeNumber++];
    return true;
  }
  return false;
}
void personalFinance::getUsrBankCards(User user){//��ȡ��ǰ�û������п�
  usrBankCards.clear();
  for(int i=0,j=0;i<int(bankCards.size());i++){
    if (bankCards[i].userID == user.ID) {
      usrBankCards[j++] = bankCards[i];
    }
  }
}
void personalFinance::getUsrBankCardTrades(BankCard theBankCard){//��ȡ��ǰ���п��Ľ��׼�¼
  usrBankCardTrades.clear();
  for(int i=0,j=0;i<int(trades.size());i++){
    if (theBankCard.ID == trades[i].cardID) {
      usrBankCardTrades[j++] = trades[i];
    }
  }
}
User personalFinance::getUser() { //��ȡ��ǰ�û���Ϣ
  return usr;
}
BankCard personalFinance::getUsrBankCard() { //��ȡ��ǰ�û�ʹ�õ����п���Ϣ
  return usrBankCard;
}
Trade personalFinance::getUsrBankCardTrade() { //��ȡ��ǰ������Ϣ
  return usrBankCardTrade;
}
int personalFinance::getUsrBankCardTradesSum() {//��ȡ��ǰ������Ϣ����н�������
  return usrBankCardTrades.size();
}
int personalFinance::getTrades(){
	return int(trades.size());
}
bool personalFinance::userModify(User user){
	for(int i=0;i<int(usrs.size());i++){
		if(usrs[i].Name==user.Name&&usrs[i].ID!=user.ID){
			return false;
		}
	}
	for(int i=0;i<int(usrs.size());i++){
		if(usrs[i].ID==user.ID){
			usrs[i]=user;
			usr=user;
			writeInfoToFile();
			break;
		}
	}
	return true;
}
void personalFinance::updateInformation(){//���µ�ǰ�û���Ϣ���˿����п���Ϣ
	readInfoFromFile();
	for(int i=0;i<int(usrs.size());i++){
		if(usrs[i].ID==usr.ID){
			usr=usrs[i];
			break;
		}
	}
	getUsrBankCards(usr);
	for(int i=0;i<int(usrBankCards.size());i++){
		if(usrBankCards[i].ID==usrBankCard.ID){
			usrBankCard=usrBankCards[i];
			break;
		}
	 }
	getUsrBankCardTrades(usrBankCard);
}
int personalFinance::getUsrsSum(){
	return int(usrs.size())+1;
}