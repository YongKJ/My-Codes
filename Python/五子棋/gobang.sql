/*
 Navicat Premium Data Transfer

 Source Server         : CentOS7
 Source Server Type    : MariaDB
 Source Server Version : 50560
 Source Host           : localhost:3307
 Source Schema         : gobang

 Target Server Type    : MariaDB
 Target Server Version : 50560
 File Encoding         : 65001

 Date: 26/08/2019 08:48:17
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for gobang_info
-- ----------------------------
DROP TABLE IF EXISTS `gobang_info`;
CREATE TABLE `gobang_info`  (
  `id` int(5) NOT NULL AUTO_INCREMENT,
  `add_time` timestamp(0) NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `robot_type` int(11) NOT NULL,
  `player_type` int(11) NOT NULL,
  `opening_type` int(11) NOT NULL,
  `five_step_choose` tinyint(1) NULL DEFAULT 0,
  `five_step_num` int(11) NULL DEFAULT 0,
  `three_step_change` tinyint(1) NULL DEFAULT 0,
  `regular_start_type` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `regular_start_name` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `regular_start_priority` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `robot_move_stack` text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `player_move_stack` text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `gobang_board_stack` mediumtext CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `gobang_info_add_time_uindex`(`add_time`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 24 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for gobang_regular_board
-- ----------------------------
DROP TABLE IF EXISTS `gobang_regular_board`;
CREATE TABLE `gobang_regular_board`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `type` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `name` varchar(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `priority` varchar(5) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `chess_board` text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 27 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for inclined
-- ----------------------------
DROP TABLE IF EXISTS `inclined`;
CREATE TABLE `inclined`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `priority` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `chess_board` text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`name`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for straight
-- ----------------------------
DROP TABLE IF EXISTS `straight`;
CREATE TABLE `straight`  (
  `name` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `priority` varchar(255) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `chess_board` text CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`name`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Table structure for test
-- ----------------------------
DROP TABLE IF EXISTS `test`;
CREATE TABLE `test`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `add_time` datetime(0) NOT NULL,
  `robot_type` int(11) NOT NULL,
  `player_type` int(11) NOT NULL,
  `opening_type` int(11) NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE INDEX `test_add_time_uindex`(`add_time`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 1 CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

SET FOREIGN_KEY_CHECKS = 1;
