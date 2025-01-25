package model

import (
	"fmt"
	"time"
	"try_GO/utils"

	"gorm.io/driver/mysql"
	"gorm.io/gorm"
)

var db *gorm.DB
var err error

func InitDb() {
	dsn := fmt.Sprintf("%s:%s@tcp(%s:%s)/%s?charset=utf8mb4&parseTime=True&loc=Local",
		utils.DbUser,
		utils.DbPassword,
		utils.DbHost,
		utils.DbPort,
		utils.DbName,
	)
	db, err = gorm.Open(mysql.Open(dsn), &gorm.Config{})

	if err != nil {
		fmt.Printf("", err)
	}

	sqldb, err := db.DB()

	if err != nil {
		fmt.Printf("", err)
	}

	db.AutoMigrate()

	// SetMaxIdleConns 用于设置连接池中空闲连接的最大数量。
	sqldb.SetMaxIdleConns(10)

	// SetMaxOpenConns 设置打开数据库连接的最大数量。
	sqldb.SetMaxOpenConns(100)

	// SetConnMaxLifetime 设置了连接可复用的最大时间。
	sqldb.SetConnMaxLifetime(time.Hour)

}
