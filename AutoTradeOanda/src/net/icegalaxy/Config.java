package net.icegalaxy;
import com.oanda.v20.account.AccountID;
import com.oanda.v20.primitives.InstrumentName;

/**
 * This is the configuration object used by the various examples to connect to
 * one of the OANDA trading systems.  Please fill them in with sane values.
 *
 * @param      URL         The fxTrade or fxPractice API URL
 * @param      TOKEN       The OANDA API Personal Access token
 * @param      ACCOUNTID   A valid v20 trading account ID that {@code TOKEN} has
 *                         permissions to take action on
 * @param      INSTRUMENT  A valid tradeable instrument for the given {@code
 *                         ACCOUNTID}
 */
public class Config {
    private Config() {}
    public static final String URL = "https://api-fxpractice.oanda.com";
    public static final String TOKEN = "606076d25540a34b3a3a17162d155b63-20338cfc57b1bf21c301665fc3b88d31";
    public static final AccountID ACCOUNTID = new AccountID("101-003-10035566-002");
    public static final InstrumentName INSTRUMENT  = new InstrumentName("EUR_USD");
}