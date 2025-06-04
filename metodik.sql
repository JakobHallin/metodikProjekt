/*M!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19  Distrib 10.6.22-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: metodik
-- ------------------------------------------------------
-- Server version	10.6.22-MariaDB-0ubuntu0.22.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Accounts`
--

DROP TABLE IF EXISTS `Accounts`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Accounts` (
  `AccountID` int(11) NOT NULL,
  `UserID` varchar(32) NOT NULL,
  `Balance` float NOT NULL,
  PRIMARY KEY (`AccountID`,`UserID`),
  UNIQUE KEY `AccountID` (`AccountID`),
  KEY `Accounts_ibfk_1` (`UserID`),
  CONSTRAINT `Accounts_ibfk_1` FOREIGN KEY (`UserID`) REFERENCES `User` (`UserID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Accounts`
--

LOCK TABLES `Accounts` WRITE;
/*!40000 ALTER TABLE `Accounts` DISABLE KEYS */;
INSERT INTO `Accounts` VALUES (1,'jakob',7127.73),(2,'jakob',1965.96),(3,'test',468),(5,'Jakob',385.84),(6,'test',499);
/*!40000 ALTER TABLE `Accounts` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `AllStocks`
--

DROP TABLE IF EXISTS `AllStocks`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `AllStocks` (
  `StocksID` int(11) NOT NULL,
  `StockName` varchar(28) NOT NULL,
  `Short` varchar(8) NOT NULL,
  UNIQUE KEY `StocksID` (`StocksID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `AllStocks`
--

LOCK TABLES `AllStocks` WRITE;
/*!40000 ALTER TABLE `AllStocks` DISABLE KEYS */;
INSERT INTO `AllStocks` VALUES (1,'Cola','KO'),(2,'Amazon','AMZN'),(3,'Apple','AAPL');
/*!40000 ALTER TABLE `AllStocks` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Stock`
--

DROP TABLE IF EXISTS `Stock`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `Stock` (
  `StocksID` int(11) NOT NULL,
  `AccountID` int(11) NOT NULL,
  `Amount` int(11) NOT NULL,
  PRIMARY KEY (`StocksID`,`AccountID`),
  KEY `Stock_ibfk_2` (`AccountID`),
  CONSTRAINT `Stock_ibfk_1` FOREIGN KEY (`StocksID`) REFERENCES `AllStocks` (`StocksID`),
  CONSTRAINT `Stock_ibfk_2` FOREIGN KEY (`AccountID`) REFERENCES `Accounts` (`AccountID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Stock`
--

LOCK TABLES `Stock` WRITE;
/*!40000 ALTER TABLE `Stock` DISABLE KEYS */;
INSERT INTO `Stock` VALUES (1,1,17),(1,2,1),(1,5,2),(2,1,69),(2,2,6);
/*!40000 ALTER TABLE `Stock` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `User`
--

DROP TABLE IF EXISTS `User`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `User` (
  `UserID` varchar(32) NOT NULL,
  `Password` varchar(42) NOT NULL,
  PRIMARY KEY (`UserID`),
  UNIQUE KEY `UserID` (`UserID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `User`
--

LOCK TABLES `User` WRITE;
/*!40000 ALTER TABLE `User` DISABLE KEYS */;
INSERT INTO `User` VALUES ('Jakob','5e52fee47e6b070565f74372468cdc699de89107'),('pas1','e3431a8e0adbf96fd140103dc6f63a3f8fa343ab '),('test','e3431a8e0adbf96fd140103dc6f63a3f8fa343ab');
/*!40000 ALTER TABLE `User` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-06-04 18:45:39
