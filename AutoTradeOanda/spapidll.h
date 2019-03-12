#include <stdint.h>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

typedef char            tinyint;
typedef unsigned char   u_tinyint;
typedef unsigned char   u_char;
typedef unsigned short  u_short;
typedef unsigned int    u_int;
typedef unsigned long   u_long;
typedef __int64          bigint;
typedef unsigned __int64 u_bigint;


typedef char STR4[4];
typedef char STR16[16];
typedef char STR40[40];

#define ORD_BUY         'B'			//����//�R�J
#define ORD_SELL        'S'			//����//��X
#define STOP_LOSS       'L'
#define STOP_UP         'U'
#define STOP_DOWN       'D'

#define AO_PRC          ((int32_t)0x7fffffff)

#define ORD_LIMIT       0			//�޼�//����
#define ORD_AUCTION     2			//������//����
#define ORD_MARKET      6			//�г���//������

#define COND_NONE       0			//һ��//�@��
#define COND_STOP       1
#define COND_SCHEDTIME  3
#define COND_OCOSTOP    4
#define COND_TRAILSTOP  6
#define COND_COMBO_OPEN     8
#define COND_COMBO_CLOSE    9
#define COND_STOP_PRC       11
#define COND_OCOSTOP_PRC    14
#define COND_TRAILSTOP_PRC  16

#define VLD_REST_OF_DAY   0
#define VLD_FILL_AND_KILL 1
#define VLD_FILL_OR_KILL  2
#define VLD_UNTIL_EXPIRE  3
#define VLD_SPEC_TIME     4

#define ACT_ADD_ORDER    1				// ���Ӷ���// �W�[�q��
#define ACT_CHANGE_ORDER 2				// �޸Ķ���// �ק�q��
#define ACT_DELETE_ORDER 3				// ɾ������// �R���q��

/*����״̬*/
#define ORDSTAT_SENDING     0			// ������// �o�e��
#define ORDSTAT_WORKING     1			// ������// �u�@��
#define ORDSTAT_INACTIVE    2			// ��Ч// �L��
#define ORDSTAT_PENDING     3			// ����// �ݩw
#define ORDSTAT_ADDING      4			// ������// �W�[��
#define ORDSTAT_CHANGING    5			// �޸���// �ק襤
#define ORDSTAT_DELETING    6			// ɾ����// �R����
#define ORDSTAT_INACTING    7			// ��Ч��// �L�Ĥ�
#define ORDSTAT_PARTTRD_WRK 8			// �����ѳɽ����һ��ڹ�����// �����w����åB�٦b�u�@��
#define ORDSTAT_TRADED      9			// �ѳɽ�// �w����
#define ORDSTAT_DELETED     10			// ��ɾ��// �w�R��
#define ORDSTAT_APPROVEWAIT 18			// �ȴ���׼ //approve wait
#define ORDSTAT_TRADEDREP   20			// traded & reported
#define ORDSTAT_DELETEDREP  21			// deleted & reported
#define ORDSTAT_RESYNC_ABN  24			// resync abnormal
#define ORDSTAT_PARTTRD_DEL 28			// partial traded & deleted
#define ORDSTAT_PARTTRD_REP 29			// partial traded & reported (deleted)

#define OC_DEFAULT              '\0'
#define OC_OPEN                 'O'
#define OC_CLOSE                'C'
#define OC_MANDATORY_CLOSE      'M'

#define SP_MAX_DEPTH    20
#define SP_MAX_LAST     20

#define CTRLMASK_CTRL_LEVEL     1  //���ڿ���:����
#define CTRLMASK_KICKOUT        2  //���ڿ���:����


typedef struct
{
    int32_t Qty;                    //���ղ�λ //�W��ܦ� 
    int32_t DepQty;                 //�洢��λ //�s�x�ܦ�  
    int32_t LongQty;                //���ճ��� //������� 
    int32_t ShortQty;               //���ն̲� //����u�� 
    double TotalAmt;             //���ճɽ� //�W�馨�� 
    double DepTotalAmt;          //���ճֲ�����(����*�۸�) //�W������`��(�ƶq*����) 
    double LongTotalAmt;         //���ճ�������(����*�۸�) //��������`��(�ƶq*����) 
    double ShortTotalAmt;        //���ն̲�����(����*�۸�) //����u���`��(�ƶq*����) 
	double PLBaseCcy;            //ӯ��(��������)
	double PL;                   //ӯ��
    double ExchangeRate;         //����
    STR16 AccNo;                 //�û�//�Τ� 
    STR16 ProdCode;              //��Լ���� //�X���N�X 
    char LongShort;              //���ճֲ��������� //�W����ܶR���V 
    tinyint DecInPrice;          //С���� //�p���I 
} SPApiPos;

typedef struct
{
    double Price;              //�۸� //���� ��
    double StopLevel;          //ֹ��۸� //��l���� ��
    double UpLevel;            //����ˮƽ //�W������ 
    double UpPrice;            //���޼۸� //�W������ ��
    double DownLevel;          //����ˮƽ //�U������ 
    double DownPrice;          //���޼۸� //�U������ ��
    bigint ExtOrderNo;         //�ⲿָʾ //�~������ 
    int32_t IntOrderNo;           //�û�������� //�Τ�q��s�� 
    int32_t Qty;                  //ʣ���� //�ѤU�ƶq
    int32_t TradedQty;            //�ѳɽ����� //�w����ƶq 
    int32_t TotalQty;             //����������//�q���`�ƶq 2012-12-20 xiaolin
    uint32_t ValidTime;            //��Чʱ�� //���Įɶ� 
    uint32_t SchedTime;            //Ԥ������ʱ�� //�w�q�o�e�ɶ� �ȤB
    uint32_t TimeStamp;            //���������ն���ʱ�� //�A�Ⱦ������q��ɶ� 
    uint32_t OrderOptions;       //����ú�Լ֧�����к��ڻ�����ʱ��(T+1),�ɽ���������Ϊ:1 //�p�G�ӦX�������������f����ɬq(T+1),�i�N���ݩʳ]��:1 
    STR16 AccNo;               //�û��ʺ� //�Τ�b�� 
    STR16 ProdCode;            //��Լ���� //�X���N�� 
    STR16 Initiator;           //�µ��û� //�U��Τ�  
    STR16 Ref;                 //�ο� //�Ѧ� 
    STR16 Ref2;                //�ο�2 //�Ѧ�2 
    STR16 GatewayCode;         //���� //���� 
    STR40 ClOrderId;           //�û��Զ������ο�//�Τ�۩w�q��Ѧ� 2012-12-20 xiaolin
    char BuySell;              //�������� //�R���V 
    char StopType;             //ֹ������ //��l����  
    char OpenClose;            //��ƽ�� //�}����  
    tinyint CondType;          //������������ //�q��������� 
    tinyint OrderType;         //�������� //�q������  
    tinyint ValidType;         //������Ч���� //�q�榳������ 
    tinyint Status;            //״̬ //���A 
    tinyint DecInPrice;        //��ԼС��λ //�X���p�Ʀ� 
	tinyint OrderAction;
	uint32_t UpdateTime;
	int32_t UpdateSeqNo;
} SPApiOrder;

typedef struct
{
    bigint BidExtOrderNo;   //Bid(��)���ⲿָʾ
    bigint AskExtOrderNo;   //Ask(��)���ⲿָʾ
    long BidAccOrderNo;     //Bid(��)�����
    long AskAccOrderNo;     //Ask(��)�����
    double BidPrice;          //Bid(��)���۸�
    double AskPrice;          //Ask(��)���۸�
    long BidQty;            //Bid(��)������
    long AskQty;            //Ask(��)������
    long SpecTime;          //Ԥ������ʱ�� //�w�q�o�e�ɶ� �ȤB
   	u_long OrderOptions;    //0=Ĭ��,1=T+1
    STR16 ProdCode;         //��Լ���� //�X���N�� 
    STR16 AccNo;            //�û��ʺ� //�Τ�b�� 
	STR40 ClOrderId;
    STR40 OrigClOrdId;
    tinyint OrderType;      //�������� //�q������  
    tinyint ValidType;      //������Ч���� //�q�榳������ 
    tinyint DecInPrice;     //��ԼС��λ //�X���p�Ʀ� 
} SPApiMMOrder;

typedef struct
{
	int32_t RecNo;		   //�ɽ���¼
    double Price;              //�ɽ��۸� //�������
	//double AvgPrice;           //�ɽ����� ��̭��AvgTradedPrice������
    bigint TradeNo;            //�ɽ���� //����s��
    bigint ExtOrderNo;         //�ⲿָʾ //�~������
    int32_t IntOrderNo;           //�û�������� //�Τ�q��s��
    int32_t Qty;                  //�ɽ����� //����ƶq
    uint32_t TradeDate;            //�ɽ����� //������
    uint32_t TradeTime;            //�ɽ�ʱ�� //����ɶ�
    STR16 AccNo;               //�û� //�Τ�
    STR16 ProdCode;            //��Լ���� //�X���N�X
    STR16 Initiator;           //�µ��û� //�U��Τ�
    STR16 Ref;                 //�ο� //�Ѧ�
    STR16 Ref2;                //�ο�2 //�Ѧ�2
    STR16 GatewayCode;         //���� //����
    STR40 ClOrderId;           //�û��Զ������ο�//�Τ�۩w�q��Ѧ� 2012-12-20 xiaolin
    char BuySell;              //�������� //�R���V
    char OpenClose;            //��ƽ�� //�}����
    tinyint Status;            //״̬ //���A
    tinyint DecInPrice;        //С��λ //�p�Ʀ�
	double OrderPrice;
	STR40 TradeRef;
	int32_t TotalQty;
	int32_t RemainingQty;
	int32_t TradedQty;
	double AvgTradedPrice;

} SPApiTrade;

#define REQMODE_UNSUBSCRIBE     0
#define REQMODE_SUBSCRIBE       1
#define REQMODE_SNAPSHOT        2


typedef struct
{
    double Margin;			//��֤��//�O�Ҫ�
    double ContractSize;		//��Լ��ֵ//�X������
    STR16 MarketCode;		//���������� //�����N�X
    STR16 InstCode;			//��Ʒϵ�д��� //���~�t�C�N�X
    STR40 InstName;			//Ӣ������ //�^��W��
    STR40 InstName1;		//�������� //�c��W��
    STR40 InstName2;		//�������� //²��W��
    STR4 Ccy;				//��Ʒϵ�еĽ��ױ��� //���~�t�C���������
    char DecInPrice;		//��Ʒϵ�е�С��λ //���~�t�C���p�Ʀ�
    char InstType;			//��Ʒϵ�е����� //���~�t�C������
} SPApiInstrument;

typedef struct
{
   STR16 ProdCode;			//��Ʒ���� //���~�N�X
   char ProdType;			//��Ʒ���� //���~����
   STR40 ProdName;			//��ƷӢ������ //���~�^��W��
   STR16 Underlying;		//�������ڻ���Լ//���p�����f�X��
   STR16 InstCode;			//��Ʒϵ������ //���~�t�C�W��
   uint32_t ExpiryDate;			//��Ʒ����ʱ�� //���~����ɶ�
   char CallPut;			//��Ȩ�����Ϲ����Ϲ� //���v��V�{�ʻP�{�f
   int32_t Strike;				//��Ȩ��ʹ��//���v��ϻ�
   int32_t LotSize;			//����//���
   STR40 ProdName1;			//��Ʒ�������� //���~�c��W��
   STR40 ProdName2;			//��Ʒ�������� //���~²��W��
   char OptStyle;			//��Ȩ������//���v������
   int32_t TickSize;			//��Ʒ�۸���С�仯λ��//���~����̤p�ܤƦ��
}SPApiProduct;

#define SP_MAX_DEPTH    20
#define SP_MAX_LAST     20
typedef struct
{
    double Bid[SP_MAX_DEPTH];     //����� //�R�J��
    int32_t BidQty[SP_MAX_DEPTH];    //������ //�R�J�q
    int32_t BidTicket[SP_MAX_DEPTH]; //��ָ������ //�R���O�ƶq
    double Ask[SP_MAX_DEPTH];     //������ //��X��
    int32_t AskQty[SP_MAX_DEPTH];    //������ //��X�q
    int32_t AskTicket[SP_MAX_DEPTH]; //��ָ������ //����O�ƶq
    double Last[SP_MAX_LAST];     //�ɽ��� //�����
    int32_t LastQty[SP_MAX_LAST];    //�ɽ����� //����ƶq
    uint32_t LastTime[SP_MAX_LAST];   //�ɽ�ʱ�� //����ɶ�
    double Equil;                 //ƽ��� //���Ż�
    double Open;                  //���̼� //�}�L��
    double High;                  //��߼� //�̰���
    double Low;                   //��ͼ� //�̧C��
    double Close;                 //���̼� //���L��
    uint32_t CloseDate;               //�������� //�������
    double TurnoverVol;           //�ܳɽ��� //�`����q
    double TurnoverAmt;           //�ܳɽ��� //�`�����B
    int32_t OpenInt;                 //δƽ�� //������
    STR16 ProdCode;               //��Լ���� //�X���N�X
    STR40 ProdName;               //��Լ���� //�X���W��
    char DecInPrice;              //��ԼС��λ //�X���p�Ʀ�
	int32_t ExStateNo;            //�����г�״̬
	int32_t TradeStateNo;         //�г�״��
	bool Suspend;                 //��Ʊ-�Ƿ���ͣ��
	int32_t ExpiryYMD;            //��Ʒ��������
 	int32_t ContractYMD;          //��Լ��������
	int32_t Timestamp;            //�������ʱ��
} SPApiPrice;

typedef struct
{
    double Price;              //�۸� //����
    int32_t Qty;                  //�ɽ��� //����q
    uint32_t TickerTime;           //ʱ�� //�ɶ�
    int32_t DealSrc;              //��Դ //�ӷ�
    STR16 ProdCode;            //��Լ���� //�X���N�X
    char DecInPrice;           //С��λ //�p�Ʀ�
} SPApiTicker;

typedef struct
{
	double NAV;               // �ʲ���ֵ				//add xiaolin 2013-03-19
    double BuyingPower;       // ������					//add xiaolin 2013-03-19
    double CashBal;           // �ֽ����				//add xiaolin 2013-03-19
	double MarginCall;        //׷�ս��
    double CommodityPL;       //��Ʒӯ��
    double LockupAmt;         //������
    double CreditLimit;       //�Ŵ��޶� // �H�U���B
    double MaxMargin;         //��߱�֤�� // �̰��O����//modif xiaolin 2012-12-20 TradeLimit
    double MaxLoanLimit;      //��߽������ // �̰��ɶU�W��
    double TradingLimit;      //���ý����~ // �H�Υ���B
    double RawMargin;         //ԭʼ���C�� // ��l�O�Ҫ�
    double IMargin;           //�������^�� //  �򥻫O����
    double MMargin;           //�S�ֱ��^�� // �����O����
    double TodayTrans;        //���׽��~ // ������B
    double LoanLimit;         //�Cȯ�ɰ���ֵ // �Ҩ�i���`��
    double TotalFee;          //�M�ÿ��~ //  �O���`�B
    double LoanToMR;	      //���/�ɰ�ֵ%
    double LoanToMV;	      //���/��ֵ%    
    STR16 AccName;            //�������Q //  ��f�W��
    STR4 BaseCcy;             //����؛�� // �򥻳f��
    STR16 MarginClass;        //���^��e // �O�������O
    STR16 TradeClass;         //����e // ������O
    STR16 ClientId;           //�͑� // �Ȥ�
    STR16 AEId;               //���o //  �g��
    char AccType;             //����e // ��f���O
    char CtrlLevel;           //���Ƽ��� //  ����ż�
    char Active;              //��Ч //  �ͮ�
    char MarginPeriod;        //�r�� // �ɬq
} SPApiAccInfo;

typedef struct
{
    double CashBf;          //���ս��� //�W�鵲�l
    double TodayCash;       //���մ�ȡ //����s��
    double NotYetValue;     //δ���� //���榬
    double Unpresented;     //δ���� //���I�{
    double TodayOut;        //��ȡҪ�� //�����n�D
    STR4 Ccy;               //���� //�f��
} SPApiAccBal;

typedef struct
{
    STR4 Ccy;
    double Rate;
} SPApiCcyRate;

#define SPDLLCALL __stdcall

/*�ص�����*/
typedef void (SPDLLCALL *LoginReplyAddr)(char* user_id, long ret_code, char *ret_msg);
typedef void (SPDLLCALL *ConnectedReplyAddr)(long host_type, long con_status);
typedef void (SPDLLCALL *ApiOrderRequestFailedAddr)(tinyint action, SPApiOrder *order, long err_code, char *err_msg);
typedef void (SPDLLCALL *ApiOrderReportAddr)(long rec_no, SPApiOrder *order);
typedef void (SPDLLCALL *ApiOrderBeforeSendReportAddr)(SPApiOrder *order);
typedef void (SPDLLCALL *AccountLoginReplyAddr)(char *accNo, long ret_code, char* ret_msg);
typedef void (SPDLLCALL *AccountLogoutReplyAddr)(char *accNo, long ret_code, char* ret_msg);
typedef void (SPDLLCALL *AccountInfoPushAddr)(SPApiAccInfo *acc_info);
typedef void (SPDLLCALL *AccountPositionPushAddr)(SPApiPos *pos);
typedef void (SPDLLCALL *UpdatedAccountPositionPushAddr)(SPApiPos *pos);
typedef void (SPDLLCALL *UpdatedAccountBalancePushAddr)(SPApiAccBal *acc_bal);
typedef void (SPDLLCALL *ApiTradeReportAddr)(long rec_no, SPApiTrade *trade);
typedef void (SPDLLCALL *ApiLoadTradeReadyPushAddr)(long rec_no, SPApiTrade *trade);
typedef void (SPDLLCALL *ApiPriceUpdateAddr)(SPApiPrice *price);
typedef void (SPDLLCALL *ApiTickerUpdateAddr)(SPApiTicker *ticker);
typedef void (SPDLLCALL *PswChangeReplyAddr)(long ret_code, char *ret_msg);
typedef void (SPDLLCALL *ProductListByCodeReplyAddr)(long req_id, char *inst_code, bool is_ready, char *ret_msg);
typedef void (SPDLLCALL *InstrumentListReplyAddr)(long req_id, bool is_ready, char *ret_msg);
typedef void (SPDLLCALL *BusinessDateReplyAddr)(long business_date);
typedef void (SPDLLCALL *ApiMMOrderBeforeSendReportAddr)(SPApiMMOrder *mm_order);
typedef void (SPDLLCALL *ApiMMOrderRequestFailedAddr)(SPApiMMOrder *mm_order, long err_code, char *err_msg);
typedef void (SPDLLCALL *ApiQuoteRequestReceivedAddr)(char *product_code, char buy_sell, long qty);
typedef void (SPDLLCALL *AccountControlReplyAddr)(long ret_code, char *ret_msg);


typedef void (SPDLLCALL *p_SPAPI_RegisterLoginReply)(LoginReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterConnectingReply)(ConnectedReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterOrderReport)(ApiOrderReportAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterOrderRequestFailed)(ApiOrderRequestFailedAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterOrderBeforeSendReport)(ApiOrderBeforeSendReportAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterAccountLoginReply)(AccountLoginReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterAccountLogoutReply)(AccountLogoutReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterAccountInfoPush)(AccountInfoPushAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterAccountPositionPush)(AccountPositionPushAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterUpdatedAccountPositionPush)(UpdatedAccountPositionPushAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterUpdatedAccountBalancePush)(UpdatedAccountBalancePushAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterTradeReport)(ApiTradeReportAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterLoadTradeReadyPush)(ApiLoadTradeReadyPushAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterApiPriceUpdate)(ApiPriceUpdateAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterTickerUpdate)(ApiTickerUpdateAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterPswChangeReply)(PswChangeReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterProductListByCodeReply)(ProductListByCodeReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterInstrumentListReply)(InstrumentListReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterBusinessDateReply)(BusinessDateReplyAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterMMOrderRequestFailed)(ApiMMOrderRequestFailedAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterMMOrderBeforeSendReport)(ApiMMOrderBeforeSendReportAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterQuoteRequestReceivedReport)(ApiQuoteRequestReceivedAddr addr);
typedef void (SPDLLCALL *p_SPAPI_RegisterAccountControlReply)(AccountControlReplyAddr addr);

typedef int  (SPDLLCALL *p_SPAPI_Initialize)();
typedef void (SPDLLCALL *p_SPAPI_SetLoginInfo)(char *host, int port, char *license, char *app_id, char *user_id, char *password);
typedef int  (SPDLLCALL *p_SPAPI_Login)();
typedef int  (SPDLLCALL *p_SPAPI_GetLoginStatus)(char *user_id, short host_id);
typedef int  (SPDLLCALL *p_SPAPI_AddOrder)(SPApiOrder *order);
typedef int (SPDLLCALL *p_SPAPI_AddInactiveOrder)(SPApiOrder* order);
typedef int (SPDLLCALL *p_SPAPI_ChangeOrder)(char *user_id, SPApiOrder* order, double org_price, long org_qty);
typedef int (SPDLLCALL *p_SPAPI_ChangeOrderBy)(char *user_id, char *acc_no, long accOrderNo, double org_price, long org_qty, double newPrice, long newQty);
typedef int (SPDLLCALL *p_SPAPI_DeleteOrderBy)(char *user_id, char *acc_no, long accOrderNo, char* productCode, char* clOrderId);
typedef int (SPDLLCALL *p_SPAPI_DeleteAllOrders)(char *user_id, char *acc_no);
typedef int (SPDLLCALL *p_SPAPI_ActivateAllOrders)(char *user_id, char *acc_no);
typedef int (SPDLLCALL *p_SPAPI_InactivateAllOrders)(char *user_id, char *acc_no);
typedef int (SPDLLCALL *p_SPAPI_ActivateOrderBy)(char *user_id, char *acc_no, long accOrderNo);
typedef int (SPDLLCALL *p_SPAPI_InactivateOrderBy)(char *user_id, char *acc_no, long accOrderNo);
typedef int  (SPDLLCALL *p_SPAPI_GetOrderCount)(char *user_id, char* acc_no);
typedef int  (SPDLLCALL *p_SPAPI_GetOrderByOrderNo)(char *user_id, char *acc_no, long int_order_no, SPApiOrder *order);
typedef int (SPDLLCALL *p_SPAPI_GetActiveOrders)(char *user_id, char *acc_no, vector<SPApiOrder>& apiOrderList);
typedef int  (SPDLLCALL *p_SPAPI_GetPosCount)(char *user_id);
typedef int  (SPDLLCALL *p_SPAPI_GetPosByProduct)(char *user_id, char *prod_code, SPApiPos *pos);
typedef int (SPDLLCALL *p_SPAPI_Uninitialize)(char *user_id);
typedef int (SPDLLCALL *p_SPAPI_Logout)(char *user_id);
typedef int (SPDLLCALL *p_SPAPI_AccountLogin)(char *user_id, char *acc_no);
typedef int (SPDLLCALL *p_SPAPI_AccountLogout)(char *user_id, char *acc_no);
typedef int  (SPDLLCALL *p_SPAPI_GetTradeCount)(char *user_id, char *acc_no);
typedef int (SPDLLCALL *p_SPAPI_GetAllTrades)(char *user_id, char *acc_no, vector<SPApiTrade>& apiTradeList);
typedef int (SPDLLCALL *p_SPAPI_SubscribePrice)(char *user_id, char *prod_code, int mode);
typedef int (SPDLLCALL *p_SPAPI_SubscribeTicker)(char *user_id, char *prod_code, int mode);
typedef int (SPDLLCALL *p_SPAPI_ChangePassword)(char *user_id, char *old_password, char *new_password);
typedef int (SPDLLCALL *p_SPAPI_GetDllVersion)(char *dll_ver_no, char *dll_rel_no, char *dll_suffix);
typedef int  (SPDLLCALL *p_SPAPI_GetAccBalCount)(char* user_id);
typedef int  (SPDLLCALL *p_SPAPI_GetAccBalByCurrency)(char *user_id, char *ccy, SPApiAccBal *acc_bal);
typedef int  (SPDLLCALL *p_SPAPI_GetAllAccBal)(char *user_id, vector<SPApiAccBal>& apiAccBalList);
typedef int  (SPDLLCALL *p_SPAPI_GetCcyRateByCcy)(char *user_id, char *ccy, double &rate);
typedef int (SPDLLCALL *p_SPAPI_GetAccInfo)(char *user_id, SPApiAccInfo *acc_info);
typedef int (SPDLLCALL *p_SPAPI_GetPriceByCode)(char *user_id, char *prod_code, SPApiPrice *price);
typedef int (SPDLLCALL *p_SPAPI_SetApiLogPath)(char *path);

typedef int (SPDLLCALL *p_SPAPI_LoadProductInfoListByMarket)(char *market_code);
typedef int (SPDLLCALL *p_SPAPI_LoadProductInfoListByCode)(char *inst_code);
typedef int (SPDLLCALL *p_SPAPI_GetProductCount)();
typedef int (SPDLLCALL *p_SPAPI_GetProduct)(vector<SPApiProduct>& apiProdList);
typedef int (SPDLLCALL *p_SPAPI_GetProductByCode)(char *prod_code, SPApiProduct *prod);

typedef int (SPDLLCALL *p_SPAPI_LoadInstrumentList)();
typedef int (SPDLLCALL *p_SPAPI_GetInstrumentCount)();
typedef int (SPDLLCALL *p_SPAPI_GetInstrument)(vector<SPApiInstrument>& apiInstList);
typedef int (SPDLLCALL *p_SPAPI_GetInstrumentByCode)(char *inst_code, SPApiInstrument *inst);
typedef int (SPDLLCALL *p_SPAPI_SetLanguageId)(int langid);

typedef int (SPDLLCALL *p_SPAPI_SendMarketMakingOrder)(char *user_id, SPApiMMOrder *mm_order);
typedef int (SPDLLCALL *p_SPAPI_SubscribeQuoteRequest)(char *user_id, char *prod_code, int mode);
typedef int (SPDLLCALL *p_SPAPI_SubscribeAllQuoteRequest)(char *user_id, int mode);

typedef int (SPDLLCALL *p_SPAPI_GetAllTradesByArray)(char *user_id, char *acc_no, SPApiTrade* apiTradeList);
typedef int (SPDLLCALL *p_SPAPI_GetOrdersByArray)(char *user_id, char *acc_no, SPApiOrder* apiOrderList);
typedef int (SPDLLCALL *p_SPAPI_GetAllAccBalByArray)(char *user_id, SPApiAccBal* apiAccBalList);
typedef int (SPDLLCALL *p_SPAPI_GetInstrumentByArray)(SPApiInstrument* apiInstList);
typedef int (SPDLLCALL *p_SPAPI_GetProductByArray)(SPApiProduct* apiProdList);

typedef int (SPDLLCALL *p_SPAPI_GetAllPos)(char *user_id, vector<SPApiPos>& apiPosList);
typedef int (SPDLLCALL *p_SPAPI_GetAllPosByArray)(char *user_id, SPApiPos* apiPosList);
typedef int (SPDLLCALL *p_SPAPI_SendAccControl)(char *user_id, char *acc_no, char ctrl_mask, char ctrl_level);