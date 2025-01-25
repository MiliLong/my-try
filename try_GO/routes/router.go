package routes

import (
	"fmt"
	"net/http"
	"try_GO/utils"

	"github.com/gin-gonic/gin"
)

func InitRouter() {
	gin.SetMode(utils.AppMode)
	r := gin.Default()

	router := r.Group("api/v1")
	{
		router.GET("hello", func(c *gin.Context) {
			c.JSON(http.StatusOK, gin.H{
				"msg": "ok",
			})
		})
	}

	R := r.Group("")
	{
		R.GET("", func(c *gin.Context) {
			c.JSON(http.StatusOK, gin.H{
				"msg": "ok",
			})
		})
	}

	if err := r.Run(utils.HttpPort); err != nil {
		fmt.Println(err)
	}
}
