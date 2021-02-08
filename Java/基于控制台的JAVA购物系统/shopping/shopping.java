package shopping;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class shopping {
	
	int time = 30;
	user usr;
	SQLUtil sql;
	Scanner sc;
	BufferedReader br;
	
	public shopping() {
		sc = new Scanner(System.in);
		br=new BufferedReader(new InputStreamReader(System.in));
	}
	
	public Boolean login() {
		//用户登录
		Boolean flag = false;
		try {
			String operation;
			String user, pass;
			sql      = new SQLUtil();
			System.out.println("**********以下操作需要您先登录，请输入用户名：**********\n");
			user     = br.readLine();
			System.out.println();
			System.out.println("请输入登录密码：\n");
			pass     = br.readLine();
			System.out.println();
			//System.out.println("user:" + user + " pass:" + pass);
			usr      = sql.login(user, pass);
			if(usr.realName.equals("#")) {
				System.out.println("\n用户名或密码不正确。请选择下一步操作：继续请按1，返回上一层请按#\n");
				operation = br.readLine();
				System.out.println();
				if(operation.equals("1")) {
					flag  = login();
				}
			}else {
				System.out.println("*******登录成功，接下来进入登录之前的操作*******\n");
				flag      = true;
			}
		}catch(Exception e) {
			System.out.println("出错了0");
		}
		return flag;
	}
	
	public void mainUI() {
		//主界面
		System.out.println("**************请选择您要的操作************");
		System.out.println("*\t\t1、会员中心\t\t*\n*\t\t2、进入购物\t\t*\n*\t\t3、试试手气\t\t*");
		System.out.println("*****************************************\n");
		int operation = sc.nextInt();
		System.out.println();
		switch(operation) {
		case 1:
			VipCenter();
			break;
		case 2:
			Shopping();
			break;
		case 3:
			Lucky();
			break;
		default:
			System.out.println("请重新选择您要的操作！\n");
			mainUI();
			break;
		}
	}
	
	public void VipCenter() {
		//会员中心
		System.out.println("**************请选择您要的操作************");
		System.out.println("*\t\t1、修改资料\t\t*\n*\t\t2、我的订单\t\t*\n*\t\t3、我的礼物\t\t*\n*\t\t4、返回上层\t\t*");
		System.out.println("*****************************************\n");
		int operation = sc.nextInt();
		System.out.println();
		switch(operation) {
			case 1:
				if(login()) {
					MyModify();
				}else {
					System.out.println("请重新选择您要的操作！\n");
					VipCenter();
				}
				break;
			case 2:
				if(login()) {
					MyOrders();
				}else {
					System.out.println("请重新选择您要的操作！\n");
					VipCenter();
				}
				break;
			case 3:
				if(login()) {
					MyGift();
				}else {
					System.out.println("请重新选择您要的操作！\n");
					VipCenter();
				}
				break;
			case 4:
				mainUI();
				break;
			default:
				System.out.println("请重新选择您要的操作！\n");
				VipCenter();
				break;
		}
	}
	public void MyModify() {
		//修改资料
		try {
			System.out.println("提供密码修改功能，请输入新密码！\n");
			usr.loginPwd     = br.readLine();
			System.out.println();
			sql.updateUserPassword(usr);
			System.out.println("更新成功，按#返回上一层，按0返回顶层。请输入：\n");
			String operation = br.readLine();
			System.out.println();
			if(operation.equals("#")) {
				VipCenter();
			}else {
				mainUI();
			}
		}catch(Exception e) {}
		
	}
	
	public void MyOrders() {
		//查看订单
		try {
			int flag = 0;
			//System.out.println(usr.id + " " + usr.realName);
			ArrayList<userData> userDatas = sql.getUserDatas(usr);
			int total_orders = userDatas.get(flag).total_orders;
			System.out.println("您的订单信息如下：\n\n订单数量：" + total_orders);
			System.out.println("-------------------------------------------------------------------------------------------------");
			for(int i = 0; i < total_orders; i++) {
				int orders_number = userDatas.get(flag).orderId;
				System.out.println("订单号：\t\t订购用户名：\t\t订购金额：\t\t订单日期：\t\t是否支付：");
				System.out.print(orders_number + "\t\t" + userDatas.get(flag).realName + "\t\t¥" + userDatas.get(flag).total_money + "\t\t\t");
				String s[] = userDatas.get(flag).addDate.split(" ");
				System.out.print(s[0] + "\t\t");
				if(userDatas.get(flag).isPlay == 0) {
					System.out.println("    否\n");
				}else {
					System.out.println("    是\n");
				}
				System.out.println("商品明细如下：\n\n商品名称：\t\t商品单价：\t\t商品数量：\t\t小计金额");
				for(int j = flag; j < userDatas.size(); j++) {
					if(userDatas.get(j).orderId == orders_number) {
						if(userDatas.get(j).goodsName.equals("篮球")||userDatas.get(j).goodsName.equals("小米手机")) {
							System.out.println(userDatas.get(j).goodsName + "\t\t\t¥" + userDatas.get(j).price + "\t\t\t   " + userDatas.get(j).number + "\t\t\t¥" + userDatas.get(j).total_price);
						}else {
							System.out.println(userDatas.get(j).goodsName + "\t\t¥" + userDatas.get(j).price + "\t\t\t   " + userDatas.get(j).number + "\t\t\t¥" + userDatas.get(j).total_price);
						}
					}else {
						flag = j;
						break;
					}
				}
				System.out.println("--------------------------------------------------------------------------------------------------");
			}
			System.out.println("\n请选择下一步操作，按#返回上一层，按0返回顶层。请输入：\n");
			String operation = br.readLine();
			System.out.println();
			if(operation.equals("#")) {
				VipCenter();
			}else {
				mainUI();
			}
		}catch(Exception e) {}
	}
	public void MyGift() {
		//我的礼物
		try {
			ArrayList<usergift> usergifts = sql.getUserGifts(usr);
			System.out.println("您获得的礼物如下：\n\n礼物数量：" + usergifts.size());
			System.out.println("---------------------------------------------");
			System.out.println("礼物名称：\t\t礼物价值:");
			for(int i = 0; i < usergifts.size(); i++) {
				if(usergifts.get(i).giftNameString.equals("8GU盘")||usergifts.get(i).giftNameString.equals("手机")) {
					System.out.println(usergifts.get(i).giftNameString + "\t\t\t" + usergifts.get(i).worth);
				}else {
					System.out.println(usergifts.get(i).giftNameString + "\t\t" + usergifts.get(i).worth);
				}
			}
			System.out.println("---------------------------------------------");
			System.out.println("\n请选择下一步操作，按#返回上一层，按0返回顶层。请输入：\n");
			String operation = br.readLine();
			System.out.println();
			if(operation.equals("#")) {
				VipCenter();
			}else {
				mainUI();
			}
		}catch(Exception e) {}
	}
	
	public void Shopping() {
		//进入购物
		System.out.println("**************请选择您要的操作************");
		System.out.println("*\t\t1、选择商品\t\t*\n*\t\t2、返回上层\t\t*");
		System.out.println("*****************************************\n");
		int operation = sc.nextInt();
		System.out.println();
		switch(operation) {
			case 1:
				if(login()) {
					buy();
				}else {
					System.out.println("请重新选择您要的操作！\n");
					Shopping();
				}
				break;
			case 2:
				mainUI();
				break;
			default:
				System.out.println("请重新选择您要的操作！\n");
				Shopping();
				break;
		}
	}
	
	public void buy() {
		//选择商品
		Boolean flag = false;
		ArrayList<product> choose = new ArrayList<product>();
		System.out.println("商品列表如下，请输入你要购买的商品编号\n");
		System.out.println("商品编号：\t\t商品名称：\t\t商品价格");
		try {
			ArrayList<good> goods = sql.getGoods();
			for(good g : goods) {
				System.out.print("   " + g.id + "\t\t\t" + g.goodsName);
				if(g.goodsName.equals("篮球")||g.goodsName.equals("小米手机")) {
					System.out.println("\t\t\t" + g.price);
				}else {
					System.out.println("\t\t" + g.price);
				}
			}
			System.out.println();
			while(true) {	
				System.out.print("请输入：\n\n");
				int goodId = sc.nextInt();
				System.out.println();
				for(good g : goods) {
					if(g.id == goodId) {
						Boolean t = false;
						for(product p : choose) {
							if(p.goodId == goodId) {
								p.number++;
								t = true;
								break;
							}
						}
						if(!t) {
							product p = new product();
							p.goodId = goodId;
							p.number = 1;
							choose.add(p);
						}
						flag = true;
						break;
					}
				}
				if(flag) {
					flag = false;
					System.out.println("商品已添加到购物车，继续选购请按1，计算请按2，返回请按#\n");
					String operation = br.readLine();
					System.out.println();
					if(operation.equals("2")) {
						int sum = 0;
						for(product p : choose) {
							sum += p.number;
						}
						System.out.println("您的购物车中有" + sum + "个商品。确定购买吗？按y付款，按#退出购买\n\n请输入：\n");
						String s = br.readLine();
						System.out.println();
						if(s.equals("y")) {
							sql.addOrder(usr);
							sql.addOrderDetail(usr, choose);
							System.out.println("输入#返回上一层，0返回顶层\n");
							String str = br.readLine();
							System.out.println();
							if(str.equals("#")) {
								Shopping();
							}else {
								mainUI();
							}
						}else {
							Shopping();
						}
						break;
					}else if(operation.equals("1")) {
						continue;
					}else if(operation.equals("#")) {
						Shopping();
						break;
					}
				}else {
					System.out.println("请输入正确的商品编号！\n");
				}
			}
		}catch(Exception e) {
			
		}
	}
	
	public void Lucky() {
		//试试手气
		System.out.println("**************请选择您要的操作************");
		System.out.println("*\t\t1、开启手气之旅\t\t*\n*\t\t2、返回上层\t\t*");
		System.out.println("*****************************************\n");
		int operation = sc.nextInt();
		System.out.println();
		switch(operation) {
			case 1:
				if(login()) {
					again();
				}else {
					System.out.println("请重新选择您要的操作！\n");
					Lucky();
				}
				break;
			case 2:
				mainUI();
				break;
			default:
				System.out.println("请重新选择您要的操作！\n");
				Lucky();
				break;
		}
	}
	
	public void again() {
		//输入幸运数字，开始抽奖
		try {
			if(time>0) {
				System.out.println("请选择0~9之间任意一个数，作为你的幸运数字。\n\n你有" + time + "次机会\n");
			}else {
				System.out.println("很遗憾，你的抽奖机会用完了！欢迎下次再来！\n");
			}
			while(time-->0) {
				Random random = new Random();
				System.out.println("请输入：\n");
				int number = sc.nextInt();
				System.out.println();
				int luckyNum = random.nextInt(10);
				if(number != luckyNum) {
					System.out.println("很遗憾，你未能获得礼物，本次幸运数是" + luckyNum + ",你还有" + time + "次机会\n");
				}else {
					ArrayList<gift> gifts = sql.getGifts();
					for(gift g : gifts) {
						if(g.id == luckyNum + 1) {
							System.out.println("恭喜，您获得以下礼物：\n\n名称：" + g.giftName + "，价值：" + g.price + "\n");
							sql.addTheIdGift(usr, luckyNum + 1);
							break;
						}
					}
				}
			}
			System.out.println("输入#返回上一层，0返回顶层\n");
			String str = br.readLine();
			System.out.println();
			if(str.equals("#")) {
				Lucky();
			}else {
				mainUI();
			}
		}catch(Exception e) {}
	}

	public static void main(String[] args) {
		shopping s = new shopping();
		s.mainUI();
	}

}
