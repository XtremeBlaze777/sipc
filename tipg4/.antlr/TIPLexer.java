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
		T__9=10, MUL=11, DIV=12, ADD=13, SUB=14, GT=15, GE=16, LT=17, LE=18, EQ=19, 
		NE=20, NUMBER=21, KALLOC=22, KINPUT=23, KWHILE=24, KIF=25, KELSE=26, KVAR=27, 
		KRETURN=28, KNULL=29, KOUTPUT=30, KERROR=31, IDENTIFIER=32, WS=33, BLOCKCOMMENT=34, 
		COMMENT=35;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "T__7", "T__8", 
			"T__9", "MUL", "DIV", "ADD", "SUB", "GT", "GE", "LT", "LE", "EQ", "NE", 
			"NUMBER", "KALLOC", "KINPUT", "KWHILE", "KIF", "KELSE", "KVAR", "KRETURN", 
			"KNULL", "KOUTPUT", "KERROR", "IDENTIFIER", "WS", "BLOCKCOMMENT", "COMMENT"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "','", "')'", "'{'", "'}'", "';'", "'.'", "'&'", "':'", 
			"'='", "'*'", "'/'", "'+'", "'-'", "'>'", "'>='", "'<'", "'<='", "'=='", 
			"'!='", null, "'alloc'", "'input'", "'while'", "'if'", "'else'", "'var'", 
			"'return'", "'null'", "'output'", "'error'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, "MUL", 
			"DIV", "ADD", "SUB", "GT", "GE", "LT", "LE", "EQ", "NE", "NUMBER", "KALLOC", 
			"KINPUT", "KWHILE", "KIF", "KELSE", "KVAR", "KRETURN", "KNULL", "KOUTPUT", 
			"KERROR", "IDENTIFIER", "WS", "BLOCKCOMMENT", "COMMENT"
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2%\u00d8\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\3\2\3\2\3\3\3\3\3\4\3\4\3\5\3\5\3\6\3\6\3\7\3"+
		"\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r\3\16\3\16\3\17\3"+
		"\17\3\20\3\20\3\21\3\21\3\21\3\22\3\22\3\23\3\23\3\23\3\24\3\24\3\24\3"+
		"\25\3\25\3\25\3\26\6\26w\n\26\r\26\16\26x\3\27\3\27\3\27\3\27\3\27\3\27"+
		"\3\30\3\30\3\30\3\30\3\30\3\30\3\31\3\31\3\31\3\31\3\31\3\31\3\32\3\32"+
		"\3\32\3\33\3\33\3\33\3\33\3\33\3\34\3\34\3\34\3\34\3\35\3\35\3\35\3\35"+
		"\3\35\3\35\3\35\3\36\3\36\3\36\3\36\3\36\3\37\3\37\3\37\3\37\3\37\3\37"+
		"\3\37\3 \3 \3 \3 \3 \3 \3!\3!\7!\u00b4\n!\f!\16!\u00b7\13!\3\"\6\"\u00ba"+
		"\n\"\r\"\16\"\u00bb\3\"\3\"\3#\3#\3#\3#\7#\u00c4\n#\f#\16#\u00c7\13#\3"+
		"#\3#\3#\3#\3#\3$\3$\3$\3$\7$\u00d2\n$\f$\16$\u00d5\13$\3$\3$\3\u00c5\2"+
		"%\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20"+
		"\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37"+
		"= ?!A\"C#E$G%\3\2\7\3\2\62;\5\2C\\aac|\6\2\62;C\\aac|\5\2\13\f\17\17\""+
		"\"\4\2\f\f\17\17\2\u00dc\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2"+
		"\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25"+
		"\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2"+
		"\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2"+
		"\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3"+
		"\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2"+
		"\2\2E\3\2\2\2\2G\3\2\2\2\3I\3\2\2\2\5K\3\2\2\2\7M\3\2\2\2\tO\3\2\2\2\13"+
		"Q\3\2\2\2\rS\3\2\2\2\17U\3\2\2\2\21W\3\2\2\2\23Y\3\2\2\2\25[\3\2\2\2\27"+
		"]\3\2\2\2\31_\3\2\2\2\33a\3\2\2\2\35c\3\2\2\2\37e\3\2\2\2!g\3\2\2\2#j"+
		"\3\2\2\2%l\3\2\2\2\'o\3\2\2\2)r\3\2\2\2+v\3\2\2\2-z\3\2\2\2/\u0080\3\2"+
		"\2\2\61\u0086\3\2\2\2\63\u008c\3\2\2\2\65\u008f\3\2\2\2\67\u0094\3\2\2"+
		"\29\u0098\3\2\2\2;\u009f\3\2\2\2=\u00a4\3\2\2\2?\u00ab\3\2\2\2A\u00b1"+
		"\3\2\2\2C\u00b9\3\2\2\2E\u00bf\3\2\2\2G\u00cd\3\2\2\2IJ\7*\2\2J\4\3\2"+
		"\2\2KL\7.\2\2L\6\3\2\2\2MN\7+\2\2N\b\3\2\2\2OP\7}\2\2P\n\3\2\2\2QR\7\177"+
		"\2\2R\f\3\2\2\2ST\7=\2\2T\16\3\2\2\2UV\7\60\2\2V\20\3\2\2\2WX\7(\2\2X"+
		"\22\3\2\2\2YZ\7<\2\2Z\24\3\2\2\2[\\\7?\2\2\\\26\3\2\2\2]^\7,\2\2^\30\3"+
		"\2\2\2_`\7\61\2\2`\32\3\2\2\2ab\7-\2\2b\34\3\2\2\2cd\7/\2\2d\36\3\2\2"+
		"\2ef\7@\2\2f \3\2\2\2gh\7@\2\2hi\7?\2\2i\"\3\2\2\2jk\7>\2\2k$\3\2\2\2"+
		"lm\7>\2\2mn\7?\2\2n&\3\2\2\2op\7?\2\2pq\7?\2\2q(\3\2\2\2rs\7#\2\2st\7"+
		"?\2\2t*\3\2\2\2uw\t\2\2\2vu\3\2\2\2wx\3\2\2\2xv\3\2\2\2xy\3\2\2\2y,\3"+
		"\2\2\2z{\7c\2\2{|\7n\2\2|}\7n\2\2}~\7q\2\2~\177\7e\2\2\177.\3\2\2\2\u0080"+
		"\u0081\7k\2\2\u0081\u0082\7p\2\2\u0082\u0083\7r\2\2\u0083\u0084\7w\2\2"+
		"\u0084\u0085\7v\2\2\u0085\60\3\2\2\2\u0086\u0087\7y\2\2\u0087\u0088\7"+
		"j\2\2\u0088\u0089\7k\2\2\u0089\u008a\7n\2\2\u008a\u008b\7g\2\2\u008b\62"+
		"\3\2\2\2\u008c\u008d\7k\2\2\u008d\u008e\7h\2\2\u008e\64\3\2\2\2\u008f"+
		"\u0090\7g\2\2\u0090\u0091\7n\2\2\u0091\u0092\7u\2\2\u0092\u0093\7g\2\2"+
		"\u0093\66\3\2\2\2\u0094\u0095\7x\2\2\u0095\u0096\7c\2\2\u0096\u0097\7"+
		"t\2\2\u00978\3\2\2\2\u0098\u0099\7t\2\2\u0099\u009a\7g\2\2\u009a\u009b"+
		"\7v\2\2\u009b\u009c\7w\2\2\u009c\u009d\7t\2\2\u009d\u009e\7p\2\2\u009e"+
		":\3\2\2\2\u009f\u00a0\7p\2\2\u00a0\u00a1\7w\2\2\u00a1\u00a2\7n\2\2\u00a2"+
		"\u00a3\7n\2\2\u00a3<\3\2\2\2\u00a4\u00a5\7q\2\2\u00a5\u00a6\7w\2\2\u00a6"+
		"\u00a7\7v\2\2\u00a7\u00a8\7r\2\2\u00a8\u00a9\7w\2\2\u00a9\u00aa\7v\2\2"+
		"\u00aa>\3\2\2\2\u00ab\u00ac\7g\2\2\u00ac\u00ad\7t\2\2\u00ad\u00ae\7t\2"+
		"\2\u00ae\u00af\7q\2\2\u00af\u00b0\7t\2\2\u00b0@\3\2\2\2\u00b1\u00b5\t"+
		"\3\2\2\u00b2\u00b4\t\4\2\2\u00b3\u00b2\3\2\2\2\u00b4\u00b7\3\2\2\2\u00b5"+
		"\u00b3\3\2\2\2\u00b5\u00b6\3\2\2\2\u00b6B\3\2\2\2\u00b7\u00b5\3\2\2\2"+
		"\u00b8\u00ba\t\5\2\2\u00b9\u00b8\3\2\2\2\u00ba\u00bb\3\2\2\2\u00bb\u00b9"+
		"\3\2\2\2\u00bb\u00bc\3\2\2\2\u00bc\u00bd\3\2\2\2\u00bd\u00be\b\"\2\2\u00be"+
		"D\3\2\2\2\u00bf\u00c0\7\61\2\2\u00c0\u00c1\7,\2\2\u00c1\u00c5\3\2\2\2"+
		"\u00c2\u00c4\13\2\2\2\u00c3\u00c2\3\2\2\2\u00c4\u00c7\3\2\2\2\u00c5\u00c6"+
		"\3\2\2\2\u00c5\u00c3\3\2\2\2\u00c6\u00c8\3\2\2\2\u00c7\u00c5\3\2\2\2\u00c8"+
		"\u00c9\7,\2\2\u00c9\u00ca\7\61\2\2\u00ca\u00cb\3\2\2\2\u00cb\u00cc\b#"+
		"\2\2\u00ccF\3\2\2\2\u00cd\u00ce\7\61\2\2\u00ce\u00cf\7\61\2\2\u00cf\u00d3"+
		"\3\2\2\2\u00d0\u00d2\n\6\2\2\u00d1\u00d0\3\2\2\2\u00d2\u00d5\3\2\2\2\u00d3"+
		"\u00d1\3\2\2\2\u00d3\u00d4\3\2\2\2\u00d4\u00d6\3\2\2\2\u00d5\u00d3\3\2"+
		"\2\2\u00d6\u00d7\b$\2\2\u00d7H\3\2\2\2\b\2x\u00b5\u00bb\u00c5\u00d3\3"+
		"\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}