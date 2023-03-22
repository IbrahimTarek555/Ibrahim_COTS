#ifndef	BIT_MATH_H_
#define BIT_MATH_H_

/*Function like macro to set a bit*/
#define SET_BIT(VAR,BIT_NUMBER)	((VAR)|=(1<<(BIT_NUMBER)))

/*Function like macro to clear a bit*/
#define CLR_BIT(VAR,BIT_NUMBER)	((VAR)&=(~(1<<(BIT_NUMBER))))

/*Function like macro to toggle a bit*/
#define TOG_BIT(VAR,BIT_NUMBER)	((VAR)^=(1<<(BIT_NUMBER)))

/*Function like macro to get a bit*/
#define GET_BIT(VAR,BIT_NUMBER)	(((VAR)>>(BIT_NUMBER))&1)

#endif