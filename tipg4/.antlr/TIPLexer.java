// Generated from c:\Users\ratik\Documents\UVA\Sem5\Compilers\sipc-mathur_phan\tipg4\TIP.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class TIPLexer extends Lexer {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, T__13=14, T__14=15, NOT=16, MUL=17, 
		DIV=18, MOD=19, ADD=20, SUB=21, GT=22, GE=23, LT=24, LE=25, EQ=26, NE=27, 
		AND=28, OR=29, LEN=30, NUMBER=31, KALLOC=32, KINPUT=33, KWHILE=34, KFOR=35, 
		KIF=36, KELSE=37, KVAR=38, KRETURN=39, KNULL=40, KOUTPUT=41, KERROR=42, 
		KTRUE=43, KFALSE=44, ARRAY=45, BOOLEAN=46, IDENTIFIER=47, WS=48, BLOCKCOMMENT=49, 
		COMMENT=50;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "T__10", "T__11", "T__12", "T__13", "T__14", "NOT", "MUL", "DIV", 
			"MOD", "ADD", "SUB", "GT", "GE", "LT", "LE", "EQ", "NE", "AND", "OR", 
			"LEN", "NUMBER", "KALLOC", "KINPUT", "KWHILE", "KFOR", "KIF", "KELSE", 
			"KVAR", "KRETURN", "KNULL", "KOUTPUT", "KERROR", "KTRUE", "KFALSE", "ARRAY", 
			"BOOLEAN", "IDENTIFIER", "WS", "BLOCKCOMMENT", "COMMENT"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "','", "')'", "'{'", "'}'", "';'", "'.'", "'&'", "'?'", 
			"':'", "'='", "'..'", "'by'", "'++'", "'--'", "'not'", "'*'", "'/'", 
			"'%'", "'+'", "'-'", "'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'and'", 
			"'or'", "'#'", null, "'alloc'", "'input'", "'while'", "'for'", "'if'", 
			"'else'", "'var'", "'return'", "'null'", "'output'", "'error'", "'true'", 
			"'false'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, null, null, "NOT", "MUL", "DIV", "MOD", "ADD", "SUB", "GT", 
			"GE", "LT", "LE", "EQ", "NE", "AND", "OR", "LEN", "NUMBER", "KALLOC", 
			"KINPUT", "KWHILE", "KFOR", "KIF", "KELSE", "KVAR", "KRETURN", "KNULL", 
			"KOUTPUT", "KERROR", "KTRUE", "KFALSE", "ARRAY", "BOOLEAN", "IDENTIFIER", 
			"WS", "BLOCKCOMMENT", "COMMENT"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}


	public TIPLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "TIP.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2\64\u012a\b\1\4\2"+
		"\t\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4"+
		"\13\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22"+
		"\t\22\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31"+
		"\t\31\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t"+
		" \4!\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t"+
		"+\4,\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\3\2"+
		"\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3"+
		"\13\3\13\3\f\3\f\3\r\3\r\3\r\3\16\3\16\3\16\3\17\3\17\3\17\3\20\3\20\3"+
		"\20\3\21\3\21\3\21\3\21\3\22\3\22\3\23\3\23\3\24\3\24\3\25\3\25\3\26\3"+
		"\26\3\27\3\27\3\30\3\30\3\30\3\31\3\31\3\32\3\32\3\32\3\33\3\33\3\33\3"+
		"\34\3\34\3\34\3\35\3\35\3\35\3\35\3\36\3\36\3\36\3\37\3\37\3 \6 \u00b2"+
		"\n \r \16 \u00b3\3!\3!\3!\3!\3!\3!\3\"\3\"\3\"\3\"\3\"\3\"\3#\3#\3#\3"+
		"#\3#\3#\3$\3$\3$\3$\3%\3%\3%\3&\3&\3&\3&\3&\3\'\3\'\3\'\3\'\3(\3(\3(\3"+
		"(\3(\3(\3(\3)\3)\3)\3)\3)\3*\3*\3*\3*\3*\3*\3*\3+\3+\3+\3+\3+\3+\3,\3"+
		",\3,\3,\3,\3-\3-\3-\3-\3-\3-\3.\3.\3.\3.\3/\3/\5/\u0102\n/\3\60\3\60\7"+
		"\60\u0106\n\60\f\60\16\60\u0109\13\60\3\61\6\61\u010c\n\61\r\61\16\61"+
		"\u010d\3\61\3\61\3\62\3\62\3\62\3\62\7\62\u0116\n\62\f\62\16\62\u0119"+
		"\13\62\3\62\3\62\3\62\3\62\3\62\3\63\3\63\3\63\3\63\7\63\u0124\n\63\f"+
		"\63\16\63\u0127\13\63\3\63\3\63\3\u0117\2\64\3\3\5\4\7\5\t\6\13\7\r\b"+
		"\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26"+
		"+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37= ?!A\"C#E$G%I&K\'M(O)Q*S"+
		"+U,W-Y.[/]\60_\61a\62c\63e\64\3\2\7\3\2\62;\5\2C\\aac|\6\2\62;C\\aac|"+
		"\5\2\13\f\17\17\"\"\4\2\f\f\17\17\2\u012f\2\3\3\2\2\2\2\5\3\2\2\2\2\7"+
		"\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2"+
		"\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2"+
		"\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2"+
		"\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2"+
		"\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2"+
		"\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M"+
		"\3\2\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3\2\2\2\2Y\3\2"+
		"\2\2\2[\3\2\2\2\2]\3\2\2\2\2_\3\2\2\2\2a\3\2\2\2\2c\3\2\2\2\2e\3\2\2\2"+
		"\3g\3\2\2\2\5i\3\2\2\2\7k\3\2\2\2\tm\3\2\2\2\13o\3\2\2\2\rq\3\2\2\2\17"+
		"s\3\2\2\2\21u\3\2\2\2\23w\3\2\2\2\25y\3\2\2\2\27{\3\2\2\2\31}\3\2\2\2"+
		"\33\u0080\3\2\2\2\35\u0083\3\2\2\2\37\u0086\3\2\2\2!\u0089\3\2\2\2#\u008d"+
		"\3\2\2\2%\u008f\3\2\2\2\'\u0091\3\2\2\2)\u0093\3\2\2\2+\u0095\3\2\2\2"+
		"-\u0097\3\2\2\2/\u0099\3\2\2\2\61\u009c\3\2\2\2\63\u009e\3\2\2\2\65\u00a1"+
		"\3\2\2\2\67\u00a4\3\2\2\29\u00a7\3\2\2\2;\u00ab\3\2\2\2=\u00ae\3\2\2\2"+
		"?\u00b1\3\2\2\2A\u00b5\3\2\2\2C\u00bb\3\2\2\2E\u00c1\3\2\2\2G\u00c7\3"+
		"\2\2\2I\u00cb\3\2\2\2K\u00ce\3\2\2\2M\u00d3\3\2\2\2O\u00d7\3\2\2\2Q\u00de"+
		"\3\2\2\2S\u00e3\3\2\2\2U\u00ea\3\2\2\2W\u00f0\3\2\2\2Y\u00f5\3\2\2\2["+
		"\u00fb\3\2\2\2]\u0101\3\2\2\2_\u0103\3\2\2\2a\u010b\3\2\2\2c\u0111\3\2"+
		"\2\2e\u011f\3\2\2\2gh\7*\2\2h\4\3\2\2\2ij\7.\2\2j\6\3\2\2\2kl\7+\2\2l"+
		"\b\3\2\2\2mn\7}\2\2n\n\3\2\2\2op\7\177\2\2p\f\3\2\2\2qr\7=\2\2r\16\3\2"+
		"\2\2st\7\60\2\2t\20\3\2\2\2uv\7(\2\2v\22\3\2\2\2wx\7A\2\2x\24\3\2\2\2"+
		"yz\7<\2\2z\26\3\2\2\2{|\7?\2\2|\30\3\2\2\2}~\7\60\2\2~\177\7\60\2\2\177"+
		"\32\3\2\2\2\u0080\u0081\7d\2\2\u0081\u0082\7{\2\2\u0082\34\3\2\2\2\u0083"+
		"\u0084\7-\2\2\u0084\u0085\7-\2\2\u0085\36\3\2\2\2\u0086\u0087\7/\2\2\u0087"+
		"\u0088\7/\2\2\u0088 \3\2\2\2\u0089\u008a\7p\2\2\u008a\u008b\7q\2\2\u008b"+
		"\u008c\7v\2\2\u008c\"\3\2\2\2\u008d\u008e\7,\2\2\u008e$\3\2\2\2\u008f"+
		"\u0090\7\61\2\2\u0090&\3\2\2\2\u0091\u0092\7\'\2\2\u0092(\3\2\2\2\u0093"+
		"\u0094\7-\2\2\u0094*\3\2\2\2\u0095\u0096\7/\2\2\u0096,\3\2\2\2\u0097\u0098"+
		"\7@\2\2\u0098.\3\2\2\2\u0099\u009a\7@\2\2\u009a\u009b\7?\2\2\u009b\60"+
		"\3\2\2\2\u009c\u009d\7>\2\2\u009d\62\3\2\2\2\u009e\u009f\7>\2\2\u009f"+
		"\u00a0\7?\2\2\u00a0\64\3\2\2\2\u00a1\u00a2\7?\2\2\u00a2\u00a3\7?\2\2\u00a3"+
		"\66\3\2\2\2\u00a4\u00a5\7#\2\2\u00a5\u00a6\7?\2\2\u00a68\3\2\2\2\u00a7"+
		"\u00a8\7c\2\2\u00a8\u00a9\7p\2\2\u00a9\u00aa\7f\2\2\u00aa:\3\2\2\2\u00ab"+
		"\u00ac\7q\2\2\u00ac\u00ad\7t\2\2\u00ad<\3\2\2\2\u00ae\u00af\7%\2\2\u00af"+
		">\3\2\2\2\u00b0\u00b2\t\2\2\2\u00b1\u00b0\3\2\2\2\u00b2\u00b3\3\2\2\2"+
		"\u00b3\u00b1\3\2\2\2\u00b3\u00b4\3\2\2\2\u00b4@\3\2\2\2\u00b5\u00b6\7"+
		"c\2\2\u00b6\u00b7\7n\2\2\u00b7\u00b8\7n\2\2\u00b8\u00b9\7q\2\2\u00b9\u00ba"+
		"\7e\2\2\u00baB\3\2\2\2\u00bb\u00bc\7k\2\2\u00bc\u00bd\7p\2\2\u00bd\u00be"+
		"\7r\2\2\u00be\u00bf\7w\2\2\u00bf\u00c0\7v\2\2\u00c0D\3\2\2\2\u00c1\u00c2"+
		"\7y\2\2\u00c2\u00c3\7j\2\2\u00c3\u00c4\7k\2\2\u00c4\u00c5\7n\2\2\u00c5"+
		"\u00c6\7g\2\2\u00c6F\3\2\2\2\u00c7\u00c8\7h\2\2\u00c8\u00c9\7q\2\2\u00c9"+
		"\u00ca\7t\2\2\u00caH\3\2\2\2\u00cb\u00cc\7k\2\2\u00cc\u00cd\7h\2\2\u00cd"+
		"J\3\2\2\2\u00ce\u00cf\7g\2\2\u00cf\u00d0\7n\2\2\u00d0\u00d1\7u\2\2\u00d1"+
		"\u00d2\7g\2\2\u00d2L\3\2\2\2\u00d3\u00d4\7x\2\2\u00d4\u00d5\7c\2\2\u00d5"+
		"\u00d6\7t\2\2\u00d6N\3\2\2\2\u00d7\u00d8\7t\2\2\u00d8\u00d9\7g\2\2\u00d9"+
		"\u00da\7v\2\2\u00da\u00db\7w\2\2\u00db\u00dc\7t\2\2\u00dc\u00dd\7p\2\2"+
		"\u00ddP\3\2\2\2\u00de\u00df\7p\2\2\u00df\u00e0\7w\2\2\u00e0\u00e1\7n\2"+
		"\2\u00e1\u00e2\7n\2\2\u00e2R\3\2\2\2\u00e3\u00e4\7q\2\2\u00e4\u00e5\7"+
		"w\2\2\u00e5\u00e6\7v\2\2\u00e6\u00e7\7r\2\2\u00e7\u00e8\7w\2\2\u00e8\u00e9"+
		"\7v\2\2\u00e9T\3\2\2\2\u00ea\u00eb\7g\2\2\u00eb\u00ec\7t\2\2\u00ec\u00ed"+
		"\7t\2\2\u00ed\u00ee\7q\2\2\u00ee\u00ef\7t\2\2\u00efV\3\2\2\2\u00f0\u00f1"+
		"\7v\2\2\u00f1\u00f2\7t\2\2\u00f2\u00f3\7w\2\2\u00f3\u00f4\7g\2\2\u00f4"+
		"X\3\2\2\2\u00f5\u00f6\7h\2\2\u00f6\u00f7\7c\2\2\u00f7\u00f8\7n\2\2\u00f8"+
		"\u00f9\7u\2\2\u00f9\u00fa\7g\2\2\u00faZ\3\2\2\2\u00fb\u00fc\7]\2\2\u00fc"+
		"\u00fd\3\2\2\2\u00fd\u00fe\7_\2\2\u00fe\\\3\2\2\2\u00ff\u0102\5W,\2\u0100"+
		"\u0102\5Y-\2\u0101\u00ff\3\2\2\2\u0101\u0100\3\2\2\2\u0102^\3\2\2\2\u0103"+
		"\u0107\t\3\2\2\u0104\u0106\t\4\2\2\u0105\u0104\3\2\2\2\u0106\u0109\3\2"+
		"\2\2\u0107\u0105\3\2\2\2\u0107\u0108\3\2\2\2\u0108`\3\2\2\2\u0109\u0107"+
		"\3\2\2\2\u010a\u010c\t\5\2\2\u010b\u010a\3\2\2\2\u010c\u010d\3\2\2\2\u010d"+
		"\u010b\3\2\2\2\u010d\u010e\3\2\2\2\u010e\u010f\3\2\2\2\u010f\u0110\b\61"+
		"\2\2\u0110b\3\2\2\2\u0111\u0112\7\61\2\2\u0112\u0113\7,\2\2\u0113\u0117"+
		"\3\2\2\2\u0114\u0116\13\2\2\2\u0115\u0114\3\2\2\2\u0116\u0119\3\2\2\2"+
		"\u0117\u0118\3\2\2\2\u0117\u0115\3\2\2\2\u0118\u011a\3\2\2\2\u0119\u0117"+
		"\3\2\2\2\u011a\u011b\7,\2\2\u011b\u011c\7\61\2\2\u011c\u011d\3\2\2\2\u011d"+
		"\u011e\b\62\2\2\u011ed\3\2\2\2\u011f\u0120\7\61\2\2\u0120\u0121\7\61\2"+
		"\2\u0121\u0125\3\2\2\2\u0122\u0124\n\6\2\2\u0123\u0122\3\2\2\2\u0124\u0127"+
		"\3\2\2\2\u0125\u0123\3\2\2\2\u0125\u0126\3\2\2\2\u0126\u0128\3\2\2\2\u0127"+
		"\u0125\3\2\2\2\u0128\u0129\b\63\2\2\u0129f\3\2\2\2\t\2\u00b3\u0101\u0107"+
		"\u010d\u0117\u0125\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}