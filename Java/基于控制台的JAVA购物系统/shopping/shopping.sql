/*
 Navicat Premium Data Transfer

 Source Server         : 我的阿里云
 Source Server Type    : MySQL
 Source Server Version : 100038
 Source Host           : 47.106.102.217:3306
 Source Schema         : shopping

 Target Server Type    : MySQL
 Target Server Version : 100038
 File Encoding         : 65001

 Date: 26/08/2019 08:51:49
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for gift
-- ----------------------------
DROP TABLE IF EXISTS `gift`;
CREATE TABLE `gift`  (
  `id` int(11) NOT NULL,
  `giftName` varchar(225) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `price` decimal(10, 2) NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of gift
-- ----------------------------
INSERT INTO `gift` VALUES (1, '8GU盘', 32.00);
INSERT INTO `gift` VALUES (2, '飞利浦P520剃须刀', 198.00);
INSERT INTO `gift` VALUES (3, '京东商城20元零食', 20.00);
INSERT INTO `gift` VALUES (4, 'IPad Mini 16G', 1980.00);
INSERT INTO `gift` VALUES (5, '小米3移动定制版', 899.00);
INSERT INTO `gift` VALUES (6, '联想平板电脑16G', 1200.00);
INSERT INTO `gift` VALUES (7, 'IPad Mini 32G', 2980.00);
INSERT INTO `gift` VALUES (8, '红米3手机', 1299.00);
INSERT INTO `gift` VALUES (9, 'QQ会员两年', 180.00);

-- ----------------------------
-- Table structure for goods
-- ----------------------------
DROP TABLE IF EXISTS `goods`;
CREATE TABLE `goods`  (
  `id` int(11) NOT NULL,
  `goodsName` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `prodArea` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `spec` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `price` decimal(10, 2) NOT NULL,
  `picture` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of goods
-- ----------------------------
INSERT INTO `goods` VALUES (1, '红双喜乒乓球拍', '上海', 'S12', 120.00, 'NULL');
INSERT INTO `goods` VALUES (2, '特步跑步机', '湖南', '双人', 3980.00, 'NULL');
INSERT INTO `goods` VALUES (3, '红尘一笑羽毛球拍', '江苏', '中号', 199.00, 'NULL');
INSERT INTO `goods` VALUES (4, '篮球', '上海', '学生专用', 78.00, 'NULL');
INSERT INTO `goods` VALUES (5, '耐克运动鞋', '广州', '均码', 299.00, 'NULL');
INSERT INTO `goods` VALUES (6, '小米手机', '北京', '4', 1800.00, 'NULL');

-- ----------------------------
-- Table structure for orderdetail
-- ----------------------------
DROP TABLE IF EXISTS `orderdetail`;
CREATE TABLE `orderdetail`  (
  `id` int(11) NOT NULL,
  `orderId` int(11) NOT NULL,
  `goodsId` int(11) NOT NULL,
  `number` int(11) NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `order`(`orderId`) USING BTREE,
  INDEX `good`(`goodsId`) USING BTREE,
  CONSTRAINT `good` FOREIGN KEY (`goodsId`) REFERENCES `goods` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `order` FOREIGN KEY (`orderId`) REFERENCES `orders` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of orderdetail
-- ----------------------------
INSERT INTO `orderdetail` VALUES (3, 6, 2, 1);
INSERT INTO `orderdetail` VALUES (4, 6, 3, 2);
INSERT INTO `orderdetail` VALUES (5, 7, 2, 1);
INSERT INTO `orderdetail` VALUES (6, 7, 5, 1);
INSERT INTO `orderdetail` VALUES (7, 8, 2, 2);
INSERT INTO `orderdetail` VALUES (8, 8, 3, 1);

-- ----------------------------
-- Table structure for orders
-- ----------------------------
DROP TABLE IF EXISTS `orders`;
CREATE TABLE `orders`  (
  `id` int(11) NOT NULL,
  `userId` int(11) NOT NULL,
  `total` decimal(10, 2) NOT NULL,
  `addDate` datetime(0) NOT NULL,
  `isPlay` int(11) NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `user1`(`userId`) USING BTREE,
  CONSTRAINT `user1` FOREIGN KEY (`userId`) REFERENCES `users` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of orders
-- ----------------------------
INSERT INTO `orders` VALUES (6, 2, 100.00, '2014-05-14 10:20:17', 0);
INSERT INTO `orders` VALUES (7, 1, 100.00, '2014-06-23 16:10:00', 0);
INSERT INTO `orders` VALUES (8, 1, 100.00, '2014-09-15 15:50:00', 0);

-- ----------------------------
-- Table structure for userGift
-- ----------------------------
DROP TABLE IF EXISTS `userGift`;
CREATE TABLE `userGift`  (
  `id` int(11) NOT NULL,
  `userId` int(11) NOT NULL,
  `giftId` int(11) NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `user`(`userId`) USING BTREE,
  INDEX `gift`(`giftId`) USING BTREE,
  CONSTRAINT `gift` FOREIGN KEY (`giftId`) REFERENCES `gift` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `user` FOREIGN KEY (`userId`) REFERENCES `users` (`id`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of userGift
-- ----------------------------
INSERT INTO `userGift` VALUES (8, 1, 3);
INSERT INTO `userGift` VALUES (9, 1, 3);

-- ----------------------------
-- Table structure for users
-- ----------------------------
DROP TABLE IF EXISTS `users`;
CREATE TABLE `users`  (
  `id` int(11) NOT NULL,
  `loginId` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `loginPwd` varchar(50) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `realName` varchar(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `score` float(7, 2) NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of users
-- ----------------------------
INSERT INTO `users` VALUES (1, 'admin', '123456', '默认管理员', 0.00);
INSERT INTO `users` VALUES (2, 'test', '123', '李地二', 0.00);

SET FOREIGN_KEY_CHECKS = 1;
