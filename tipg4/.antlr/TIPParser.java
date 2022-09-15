// Generated from c:\Users\ratik\Documents\UVA\Sem5\Compilers\sipc-mathur_phan\tipg4\TIP.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class TIPParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		T__0=1, T__1=2, T__2=3, T__3=4, T__4=5, T__5=6, T__6=7, T__7=8, T__8=9, 
		T__9=10, T__10=11, T__11=12, T__12=13, NOT=14, MUL=15, DIV=16, MOD=17, 
		ADD=18, SUB=19, GT=20, GE=21, LT=22, LE=23, EQ=24, NE=25, AND=26, OR=27, 
		NUMBER=28, KALLOC=29, KINPUT=30, KWHILE=31, KIF=32, KELSE=33, KVAR=34, 
		KRETURN=35, KNULL=36, KOUTPUT=37, KERROR=38, KTRUE=39, KFALSE=40, BOOLEAN=41, 
		IDENTIFIER=42, WS=43, BLOCKCOMMENT=44, COMMENT=45;
	public static final int
		RULE_program = 0, RULE_function = 1, RULE_declaration = 2, RULE_nameDeclaration = 3, 
		RULE_expr = 4, RULE_recordExpr = 5, RULE_fieldExpr = 6, RULE_statement = 7, 
		RULE_assignStmt = 8, RULE_blockStmt = 9, RULE_whileStmt = 10, RULE_ifStmt = 11, 
		RULE_outputStmt = 12, RULE_errorStmt = 13, RULE_returnStmt = 14, RULE_incStmt = 15, 
		RULE_decStmt = 16;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "function", "declaration", "nameDeclaration", "expr", "recordExpr", 
			"fieldExpr", "statement", "assignStmt", "blockStmt", "whileStmt", "ifStmt", 
			"outputStmt", "errorStmt", "returnStmt", "incStmt", "decStmt"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'('", "','", "')'", "'{'", "'}'", "';'", "'.'", "'&'", "'?'", 
			"':'", "'='", "'++'", "'--'", "'not'", "'*'", "'/'", "'%'", "'+'", "'-'", 
			"'>'", "'>='", "'<'", "'<='", "'=='", "'!='", "'and'", "'or'", null, 
			"'alloc'", "'input'", "'while'", "'if'", "'else'", "'var'", "'return'", 
			"'null'", "'output'", "'error'", "'true'", "'false'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, null, null, null, null, null, null, null, null, null, null, null, 
			null, null, "NOT", "MUL", "DIV", "MOD", "ADD", "SUB", "GT", "GE", "LT", 
			"LE", "EQ", "NE", "AND", "OR", "NUMBER", "KALLOC", "KINPUT", "KWHILE", 
			"KIF", "KELSE", "KVAR", "KRETURN", "KNULL", "KOUTPUT", "KERROR", "KTRUE", 
			"KFALSE", "BOOLEAN", "IDENTIFIER", "WS", "BLOCKCOMMENT", "COMMENT"
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

	@Override
	public String getGrammarFileName() { return "TIP.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public TIPParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgramContext extends ParserRuleContext {
		public List<FunctionContext> function() {
			return getRuleContexts(FunctionContext.class);
		}
		public FunctionContext function(int i) {
			return getRuleContext(FunctionContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(35); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(34);
				function();
				}
				}
				setState(37); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==IDENTIFIER );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionContext extends ParserRuleContext {
		public List<NameDeclarationContext> nameDeclaration() {
			return getRuleContexts(NameDeclarationContext.class);
		}
		public NameDeclarationContext nameDeclaration(int i) {
			return getRuleContext(NameDeclarationContext.class,i);
		}
		public ReturnStmtContext returnStmt() {
			return getRuleContext(ReturnStmtContext.class,0);
		}
		public List<DeclarationContext> declaration() {
			return getRuleContexts(DeclarationContext.class);
		}
		public DeclarationContext declaration(int i) {
			return getRuleContext(DeclarationContext.class,i);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public FunctionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_function; }
	}

	public final FunctionContext function() throws RecognitionException {
		FunctionContext _localctx = new FunctionContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_function);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(39);
			nameDeclaration();
			setState(40);
			match(T__0);
			setState(49);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IDENTIFIER) {
				{
				setState(41);
				nameDeclaration();
				setState(46);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__1) {
					{
					{
					setState(42);
					match(T__1);
					setState(43);
					nameDeclaration();
					}
					}
					setState(48);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(51);
			match(T__2);
			setState(52);
			match(T__3);
			{
			setState(56);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==KVAR) {
				{
				{
				setState(53);
				declaration();
				}
				}
				setState(58);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
			{
			setState(62);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__3) | (1L << T__7) | (1L << NOT) | (1L << MUL) | (1L << SUB) | (1L << NUMBER) | (1L << KALLOC) | (1L << KINPUT) | (1L << KWHILE) | (1L << KIF) | (1L << KNULL) | (1L << KOUTPUT) | (1L << KERROR) | (1L << BOOLEAN) | (1L << IDENTIFIER))) != 0)) {
				{
				{
				setState(59);
				statement();
				}
				}
				setState(64);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
			setState(65);
			returnStmt();
			setState(66);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationContext extends ParserRuleContext {
		public TerminalNode KVAR() { return getToken(TIPParser.KVAR, 0); }
		public List<NameDeclarationContext> nameDeclaration() {
			return getRuleContexts(NameDeclarationContext.class);
		}
		public NameDeclarationContext nameDeclaration(int i) {
			return getRuleContext(NameDeclarationContext.class,i);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_declaration);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(68);
			match(KVAR);
			setState(69);
			nameDeclaration();
			setState(74);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==T__1) {
				{
				{
				setState(70);
				match(T__1);
				setState(71);
				nameDeclaration();
				}
				}
				setState(76);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(77);
			match(T__5);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NameDeclarationContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(TIPParser.IDENTIFIER, 0); }
		public NameDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_nameDeclaration; }
	}

	public final NameDeclarationContext nameDeclaration() throws RecognitionException {
		NameDeclarationContext _localctx = new NameDeclarationContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_nameDeclaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(79);
			match(IDENTIFIER);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
	 
		public ExprContext() { }
		public void copyFrom(ExprContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class RecordRuleContext extends ExprContext {
		public RecordExprContext recordExpr() {
			return getRuleContext(RecordExprContext.class,0);
		}
		public RecordRuleContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class NullExprContext extends ExprContext {
		public TerminalNode KNULL() { return getToken(TIPParser.KNULL, 0); }
		public NullExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class AllocExprContext extends ExprContext {
		public TerminalNode KALLOC() { return getToken(TIPParser.KALLOC, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public AllocExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class NegNumberContext extends ExprContext {
		public TerminalNode SUB() { return getToken(TIPParser.SUB, 0); }
		public TerminalNode NUMBER() { return getToken(TIPParser.NUMBER, 0); }
		public NegNumberContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class InputExprContext extends ExprContext {
		public TerminalNode KINPUT() { return getToken(TIPParser.KINPUT, 0); }
		public InputExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class AdditiveExprContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode ADD() { return getToken(TIPParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(TIPParser.SUB, 0); }
		public AdditiveExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class BitwiseAndContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode AND() { return getToken(TIPParser.AND, 0); }
		public BitwiseAndContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class RelationalExprContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode GT() { return getToken(TIPParser.GT, 0); }
		public TerminalNode GE() { return getToken(TIPParser.GE, 0); }
		public TerminalNode LT() { return getToken(TIPParser.LT, 0); }
		public TerminalNode LE() { return getToken(TIPParser.LE, 0); }
		public RelationalExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class DeRefExprContext extends ExprContext {
		public TerminalNode MUL() { return getToken(TIPParser.MUL, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public DeRefExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class NumExprContext extends ExprContext {
		public TerminalNode NUMBER() { return getToken(TIPParser.NUMBER, 0); }
		public NumExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ParenExprContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ParenExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class ArithmeticNegationContext extends ExprContext {
		public TerminalNode SUB() { return getToken(TIPParser.SUB, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ArithmeticNegationContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class VarExprContext extends ExprContext {
		public TerminalNode IDENTIFIER() { return getToken(TIPParser.IDENTIFIER, 0); }
		public VarExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class TernaryExprContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TernaryExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class RefExprContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public RefExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class UnaryNegationContext extends ExprContext {
		public TerminalNode NOT() { return getToken(TIPParser.NOT, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public UnaryNegationContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class BitwiseOrContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode OR() { return getToken(TIPParser.OR, 0); }
		public BitwiseOrContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class BoolExprContext extends ExprContext {
		public TerminalNode BOOLEAN() { return getToken(TIPParser.BOOLEAN, 0); }
		public BoolExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class MultiplicativeExprContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode MUL() { return getToken(TIPParser.MUL, 0); }
		public TerminalNode DIV() { return getToken(TIPParser.DIV, 0); }
		public TerminalNode MOD() { return getToken(TIPParser.MOD, 0); }
		public MultiplicativeExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class FunAppExprContext extends ExprContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public FunAppExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class EqualityExprContext extends ExprContext {
		public Token op;
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public TerminalNode EQ() { return getToken(TIPParser.EQ, 0); }
		public TerminalNode NE() { return getToken(TIPParser.NE, 0); }
		public EqualityExprContext(ExprContext ctx) { copyFrom(ctx); }
	}
	public static class AccessExprContext extends ExprContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode IDENTIFIER() { return getToken(TIPParser.IDENTIFIER, 0); }
		public AccessExprContext(ExprContext ctx) { copyFrom(ctx); }
	}

	public final ExprContext expr() throws RecognitionException {
		return expr(0);
	}

	private ExprContext expr(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExprContext _localctx = new ExprContext(_ctx, _parentState);
		ExprContext _prevctx = _localctx;
		int _startState = 8;
		enterRecursionRule(_localctx, 8, RULE_expr, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(104);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				{
				_localctx = new DeRefExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(82);
				match(MUL);
				setState(83);
				expr(20);
				}
				break;
			case 2:
				{
				_localctx = new NegNumberContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(84);
				match(SUB);
				setState(85);
				match(NUMBER);
				}
				break;
			case 3:
				{
				_localctx = new RefExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(86);
				match(T__7);
				setState(87);
				expr(18);
				}
				break;
			case 4:
				{
				_localctx = new UnaryNegationContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(88);
				match(NOT);
				setState(89);
				expr(17);
				}
				break;
			case 5:
				{
				_localctx = new ArithmeticNegationContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(90);
				match(SUB);
				setState(91);
				expr(14);
				}
				break;
			case 6:
				{
				_localctx = new BoolExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(92);
				match(BOOLEAN);
				}
				break;
			case 7:
				{
				_localctx = new VarExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(93);
				match(IDENTIFIER);
				}
				break;
			case 8:
				{
				_localctx = new NumExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(94);
				match(NUMBER);
				}
				break;
			case 9:
				{
				_localctx = new InputExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(95);
				match(KINPUT);
				}
				break;
			case 10:
				{
				_localctx = new AllocExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(96);
				match(KALLOC);
				setState(97);
				expr(4);
				}
				break;
			case 11:
				{
				_localctx = new NullExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(98);
				match(KNULL);
				}
				break;
			case 12:
				{
				_localctx = new RecordRuleContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(99);
				recordExpr();
				}
				break;
			case 13:
				{
				_localctx = new ParenExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(100);
				match(T__0);
				setState(101);
				expr(0);
				setState(102);
				match(T__2);
				}
				break;
			}
			_ctx.stop = _input.LT(-1);
			setState(148);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(146);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
					case 1:
						{
						_localctx = new MultiplicativeExprContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(106);
						if (!(precpred(_ctx, 16))) throw new FailedPredicateException(this, "precpred(_ctx, 16)");
						setState(107);
						((MultiplicativeExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << MUL) | (1L << DIV) | (1L << MOD))) != 0)) ) {
							((MultiplicativeExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(108);
						expr(17);
						}
						break;
					case 2:
						{
						_localctx = new AdditiveExprContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(109);
						if (!(precpred(_ctx, 15))) throw new FailedPredicateException(this, "precpred(_ctx, 15)");
						setState(110);
						((AdditiveExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==ADD || _la==SUB) ) {
							((AdditiveExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(111);
						expr(16);
						}
						break;
					case 3:
						{
						_localctx = new RelationalExprContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(112);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(113);
						((RelationalExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << GT) | (1L << GE) | (1L << LT) | (1L << LE))) != 0)) ) {
							((RelationalExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(114);
						expr(14);
						}
						break;
					case 4:
						{
						_localctx = new EqualityExprContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(115);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(116);
						((EqualityExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==EQ || _la==NE) ) {
							((EqualityExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(117);
						expr(13);
						}
						break;
					case 5:
						{
						_localctx = new BitwiseAndContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(118);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(119);
						match(AND);
						setState(120);
						expr(12);
						}
						break;
					case 6:
						{
						_localctx = new BitwiseOrContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(121);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(122);
						match(OR);
						setState(123);
						expr(11);
						}
						break;
					case 7:
						{
						_localctx = new TernaryExprContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(124);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(125);
						match(T__8);
						setState(126);
						expr(0);
						setState(127);
						match(T__9);
						setState(128);
						expr(10);
						}
						break;
					case 8:
						{
						_localctx = new FunAppExprContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(130);
						if (!(precpred(_ctx, 22))) throw new FailedPredicateException(this, "precpred(_ctx, 22)");
						setState(131);
						match(T__0);
						setState(140);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__3) | (1L << T__7) | (1L << NOT) | (1L << MUL) | (1L << SUB) | (1L << NUMBER) | (1L << KALLOC) | (1L << KINPUT) | (1L << KNULL) | (1L << BOOLEAN) | (1L << IDENTIFIER))) != 0)) {
							{
							setState(132);
							expr(0);
							setState(137);
							_errHandler.sync(this);
							_la = _input.LA(1);
							while (_la==T__1) {
								{
								{
								setState(133);
								match(T__1);
								setState(134);
								expr(0);
								}
								}
								setState(139);
								_errHandler.sync(this);
								_la = _input.LA(1);
							}
							}
						}

						setState(142);
						match(T__2);
						}
						break;
					case 9:
						{
						_localctx = new AccessExprContext(new ExprContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expr);
						setState(143);
						if (!(precpred(_ctx, 21))) throw new FailedPredicateException(this, "precpred(_ctx, 21)");
						setState(144);
						match(T__6);
						setState(145);
						match(IDENTIFIER);
						}
						break;
					}
					} 
				}
				setState(150);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,10,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class RecordExprContext extends ParserRuleContext {
		public List<FieldExprContext> fieldExpr() {
			return getRuleContexts(FieldExprContext.class);
		}
		public FieldExprContext fieldExpr(int i) {
			return getRuleContext(FieldExprContext.class,i);
		}
		public RecordExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_recordExpr; }
	}

	public final RecordExprContext recordExpr() throws RecognitionException {
		RecordExprContext _localctx = new RecordExprContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_recordExpr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(151);
			match(T__3);
			setState(160);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IDENTIFIER) {
				{
				setState(152);
				fieldExpr();
				setState(157);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==T__1) {
					{
					{
					setState(153);
					match(T__1);
					setState(154);
					fieldExpr();
					}
					}
					setState(159);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(162);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FieldExprContext extends ParserRuleContext {
		public TerminalNode IDENTIFIER() { return getToken(TIPParser.IDENTIFIER, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public FieldExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fieldExpr; }
	}

	public final FieldExprContext fieldExpr() throws RecognitionException {
		FieldExprContext _localctx = new FieldExprContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_fieldExpr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(164);
			match(IDENTIFIER);
			setState(165);
			match(T__9);
			setState(166);
			expr(0);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public BlockStmtContext blockStmt() {
			return getRuleContext(BlockStmtContext.class,0);
		}
		public IncStmtContext incStmt() {
			return getRuleContext(IncStmtContext.class,0);
		}
		public DecStmtContext decStmt() {
			return getRuleContext(DecStmtContext.class,0);
		}
		public AssignStmtContext assignStmt() {
			return getRuleContext(AssignStmtContext.class,0);
		}
		public WhileStmtContext whileStmt() {
			return getRuleContext(WhileStmtContext.class,0);
		}
		public IfStmtContext ifStmt() {
			return getRuleContext(IfStmtContext.class,0);
		}
		public OutputStmtContext outputStmt() {
			return getRuleContext(OutputStmtContext.class,0);
		}
		public ErrorStmtContext errorStmt() {
			return getRuleContext(ErrorStmtContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_statement);
		try {
			setState(176);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(168);
				blockStmt();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(169);
				incStmt();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(170);
				decStmt();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(171);
				assignStmt();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(172);
				whileStmt();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(173);
				ifStmt();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(174);
				outputStmt();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(175);
				errorStmt();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignStmtContext extends ParserRuleContext {
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public AssignStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignStmt; }
	}

	public final AssignStmtContext assignStmt() throws RecognitionException {
		AssignStmtContext _localctx = new AssignStmtContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_assignStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(178);
			expr(0);
			setState(179);
			match(T__10);
			setState(180);
			expr(0);
			setState(181);
			match(T__5);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockStmtContext extends ParserRuleContext {
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public BlockStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_blockStmt; }
	}

	public final BlockStmtContext blockStmt() throws RecognitionException {
		BlockStmtContext _localctx = new BlockStmtContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_blockStmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(183);
			match(T__3);
			{
			setState(187);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << T__0) | (1L << T__3) | (1L << T__7) | (1L << NOT) | (1L << MUL) | (1L << SUB) | (1L << NUMBER) | (1L << KALLOC) | (1L << KINPUT) | (1L << KWHILE) | (1L << KIF) | (1L << KNULL) | (1L << KOUTPUT) | (1L << KERROR) | (1L << BOOLEAN) | (1L << IDENTIFIER))) != 0)) {
				{
				{
				setState(184);
				statement();
				}
				}
				setState(189);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
			setState(190);
			match(T__4);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhileStmtContext extends ParserRuleContext {
		public TerminalNode KWHILE() { return getToken(TIPParser.KWHILE, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public StatementContext statement() {
			return getRuleContext(StatementContext.class,0);
		}
		public WhileStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileStmt; }
	}

	public final WhileStmtContext whileStmt() throws RecognitionException {
		WhileStmtContext _localctx = new WhileStmtContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_whileStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(192);
			match(KWHILE);
			setState(193);
			match(T__0);
			setState(194);
			expr(0);
			setState(195);
			match(T__2);
			setState(196);
			statement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfStmtContext extends ParserRuleContext {
		public TerminalNode KIF() { return getToken(TIPParser.KIF, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public TerminalNode KELSE() { return getToken(TIPParser.KELSE, 0); }
		public IfStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifStmt; }
	}

	public final IfStmtContext ifStmt() throws RecognitionException {
		IfStmtContext _localctx = new IfStmtContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_ifStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(198);
			match(KIF);
			setState(199);
			match(T__0);
			setState(200);
			expr(0);
			setState(201);
			match(T__2);
			setState(202);
			statement();
			setState(205);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,15,_ctx) ) {
			case 1:
				{
				setState(203);
				match(KELSE);
				setState(204);
				statement();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OutputStmtContext extends ParserRuleContext {
		public TerminalNode KOUTPUT() { return getToken(TIPParser.KOUTPUT, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public OutputStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_outputStmt; }
	}

	public final OutputStmtContext outputStmt() throws RecognitionException {
		OutputStmtContext _localctx = new OutputStmtContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_outputStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(207);
			match(KOUTPUT);
			setState(208);
			expr(0);
			setState(209);
			match(T__5);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ErrorStmtContext extends ParserRuleContext {
		public TerminalNode KERROR() { return getToken(TIPParser.KERROR, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ErrorStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_errorStmt; }
	}

	public final ErrorStmtContext errorStmt() throws RecognitionException {
		ErrorStmtContext _localctx = new ErrorStmtContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_errorStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(211);
			match(KERROR);
			setState(212);
			expr(0);
			setState(213);
			match(T__5);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ReturnStmtContext extends ParserRuleContext {
		public TerminalNode KRETURN() { return getToken(TIPParser.KRETURN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ReturnStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_returnStmt; }
	}

	public final ReturnStmtContext returnStmt() throws RecognitionException {
		ReturnStmtContext _localctx = new ReturnStmtContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_returnStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(215);
			match(KRETURN);
			setState(216);
			expr(0);
			setState(217);
			match(T__5);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IncStmtContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public IncStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_incStmt; }
	}

	public final IncStmtContext incStmt() throws RecognitionException {
		IncStmtContext _localctx = new IncStmtContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_incStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(219);
			expr(0);
			setState(220);
			match(T__11);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DecStmtContext extends ParserRuleContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public DecStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_decStmt; }
	}

	public final DecStmtContext decStmt() throws RecognitionException {
		DecStmtContext _localctx = new DecStmtContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_decStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(222);
			expr(0);
			setState(223);
			match(T__12);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 4:
			return expr_sempred((ExprContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expr_sempred(ExprContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 16);
		case 1:
			return precpred(_ctx, 15);
		case 2:
			return precpred(_ctx, 13);
		case 3:
			return precpred(_ctx, 12);
		case 4:
			return precpred(_ctx, 11);
		case 5:
			return precpred(_ctx, 10);
		case 6:
			return precpred(_ctx, 9);
		case 7:
			return precpred(_ctx, 22);
		case 8:
			return precpred(_ctx, 21);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3/\u00e4\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\3\2\6\2&\n\2\r\2\16\2\'\3\3\3\3\3\3\3\3\3\3\7\3/\n\3\f\3\16\3\62\13\3"+
		"\5\3\64\n\3\3\3\3\3\3\3\7\39\n\3\f\3\16\3<\13\3\3\3\7\3?\n\3\f\3\16\3"+
		"B\13\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\7\4K\n\4\f\4\16\4N\13\4\3\4\3\4\3\5"+
		"\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3"+
		"\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6k\n\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3"+
		"\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6"+
		"\3\6\3\6\3\6\7\6\u008a\n\6\f\6\16\6\u008d\13\6\5\6\u008f\n\6\3\6\3\6\3"+
		"\6\3\6\7\6\u0095\n\6\f\6\16\6\u0098\13\6\3\7\3\7\3\7\3\7\7\7\u009e\n\7"+
		"\f\7\16\7\u00a1\13\7\5\7\u00a3\n\7\3\7\3\7\3\b\3\b\3\b\3\b\3\t\3\t\3\t"+
		"\3\t\3\t\3\t\3\t\3\t\5\t\u00b3\n\t\3\n\3\n\3\n\3\n\3\n\3\13\3\13\7\13"+
		"\u00bc\n\13\f\13\16\13\u00bf\13\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3"+
		"\r\3\r\3\r\3\r\3\r\3\r\3\r\5\r\u00d0\n\r\3\16\3\16\3\16\3\16\3\17\3\17"+
		"\3\17\3\17\3\20\3\20\3\20\3\20\3\21\3\21\3\21\3\22\3\22\3\22\3\22\2\3"+
		"\n\23\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"\2\6\3\2\21\23\3\2\24\25"+
		"\3\2\26\31\3\2\32\33\2\u00fa\2%\3\2\2\2\4)\3\2\2\2\6F\3\2\2\2\bQ\3\2\2"+
		"\2\nj\3\2\2\2\f\u0099\3\2\2\2\16\u00a6\3\2\2\2\20\u00b2\3\2\2\2\22\u00b4"+
		"\3\2\2\2\24\u00b9\3\2\2\2\26\u00c2\3\2\2\2\30\u00c8\3\2\2\2\32\u00d1\3"+
		"\2\2\2\34\u00d5\3\2\2\2\36\u00d9\3\2\2\2 \u00dd\3\2\2\2\"\u00e0\3\2\2"+
		"\2$&\5\4\3\2%$\3\2\2\2&\'\3\2\2\2\'%\3\2\2\2\'(\3\2\2\2(\3\3\2\2\2)*\5"+
		"\b\5\2*\63\7\3\2\2+\60\5\b\5\2,-\7\4\2\2-/\5\b\5\2.,\3\2\2\2/\62\3\2\2"+
		"\2\60.\3\2\2\2\60\61\3\2\2\2\61\64\3\2\2\2\62\60\3\2\2\2\63+\3\2\2\2\63"+
		"\64\3\2\2\2\64\65\3\2\2\2\65\66\7\5\2\2\66:\7\6\2\2\679\5\6\4\28\67\3"+
		"\2\2\29<\3\2\2\2:8\3\2\2\2:;\3\2\2\2;@\3\2\2\2<:\3\2\2\2=?\5\20\t\2>="+
		"\3\2\2\2?B\3\2\2\2@>\3\2\2\2@A\3\2\2\2AC\3\2\2\2B@\3\2\2\2CD\5\36\20\2"+
		"DE\7\7\2\2E\5\3\2\2\2FG\7$\2\2GL\5\b\5\2HI\7\4\2\2IK\5\b\5\2JH\3\2\2\2"+
		"KN\3\2\2\2LJ\3\2\2\2LM\3\2\2\2MO\3\2\2\2NL\3\2\2\2OP\7\b\2\2P\7\3\2\2"+
		"\2QR\7,\2\2R\t\3\2\2\2ST\b\6\1\2TU\7\21\2\2Uk\5\n\6\26VW\7\25\2\2Wk\7"+
		"\36\2\2XY\7\n\2\2Yk\5\n\6\24Z[\7\20\2\2[k\5\n\6\23\\]\7\25\2\2]k\5\n\6"+
		"\20^k\7+\2\2_k\7,\2\2`k\7\36\2\2ak\7 \2\2bc\7\37\2\2ck\5\n\6\6dk\7&\2"+
		"\2ek\5\f\7\2fg\7\3\2\2gh\5\n\6\2hi\7\5\2\2ik\3\2\2\2jS\3\2\2\2jV\3\2\2"+
		"\2jX\3\2\2\2jZ\3\2\2\2j\\\3\2\2\2j^\3\2\2\2j_\3\2\2\2j`\3\2\2\2ja\3\2"+
		"\2\2jb\3\2\2\2jd\3\2\2\2je\3\2\2\2jf\3\2\2\2k\u0096\3\2\2\2lm\f\22\2\2"+
		"mn\t\2\2\2n\u0095\5\n\6\23op\f\21\2\2pq\t\3\2\2q\u0095\5\n\6\22rs\f\17"+
		"\2\2st\t\4\2\2t\u0095\5\n\6\20uv\f\16\2\2vw\t\5\2\2w\u0095\5\n\6\17xy"+
		"\f\r\2\2yz\7\34\2\2z\u0095\5\n\6\16{|\f\f\2\2|}\7\35\2\2}\u0095\5\n\6"+
		"\r~\177\f\13\2\2\177\u0080\7\13\2\2\u0080\u0081\5\n\6\2\u0081\u0082\7"+
		"\f\2\2\u0082\u0083\5\n\6\f\u0083\u0095\3\2\2\2\u0084\u0085\f\30\2\2\u0085"+
		"\u008e\7\3\2\2\u0086\u008b\5\n\6\2\u0087\u0088\7\4\2\2\u0088\u008a\5\n"+
		"\6\2\u0089\u0087\3\2\2\2\u008a\u008d\3\2\2\2\u008b\u0089\3\2\2\2\u008b"+
		"\u008c\3\2\2\2\u008c\u008f\3\2\2\2\u008d\u008b\3\2\2\2\u008e\u0086\3\2"+
		"\2\2\u008e\u008f\3\2\2\2\u008f\u0090\3\2\2\2\u0090\u0095\7\5\2\2\u0091"+
		"\u0092\f\27\2\2\u0092\u0093\7\t\2\2\u0093\u0095\7,\2\2\u0094l\3\2\2\2"+
		"\u0094o\3\2\2\2\u0094r\3\2\2\2\u0094u\3\2\2\2\u0094x\3\2\2\2\u0094{\3"+
		"\2\2\2\u0094~\3\2\2\2\u0094\u0084\3\2\2\2\u0094\u0091\3\2\2\2\u0095\u0098"+
		"\3\2\2\2\u0096\u0094\3\2\2\2\u0096\u0097\3\2\2\2\u0097\13\3\2\2\2\u0098"+
		"\u0096\3\2\2\2\u0099\u00a2\7\6\2\2\u009a\u009f\5\16\b\2\u009b\u009c\7"+
		"\4\2\2\u009c\u009e\5\16\b\2\u009d\u009b\3\2\2\2\u009e\u00a1\3\2\2\2\u009f"+
		"\u009d\3\2\2\2\u009f\u00a0\3\2\2\2\u00a0\u00a3\3\2\2\2\u00a1\u009f\3\2"+
		"\2\2\u00a2\u009a\3\2\2\2\u00a2\u00a3\3\2\2\2\u00a3\u00a4\3\2\2\2\u00a4"+
		"\u00a5\7\7\2\2\u00a5\r\3\2\2\2\u00a6\u00a7\7,\2\2\u00a7\u00a8\7\f\2\2"+
		"\u00a8\u00a9\5\n\6\2\u00a9\17\3\2\2\2\u00aa\u00b3\5\24\13\2\u00ab\u00b3"+
		"\5 \21\2\u00ac\u00b3\5\"\22\2\u00ad\u00b3\5\22\n\2\u00ae\u00b3\5\26\f"+
		"\2\u00af\u00b3\5\30\r\2\u00b0\u00b3\5\32\16\2\u00b1\u00b3\5\34\17\2\u00b2"+
		"\u00aa\3\2\2\2\u00b2\u00ab\3\2\2\2\u00b2\u00ac\3\2\2\2\u00b2\u00ad\3\2"+
		"\2\2\u00b2\u00ae\3\2\2\2\u00b2\u00af\3\2\2\2\u00b2\u00b0\3\2\2\2\u00b2"+
		"\u00b1\3\2\2\2\u00b3\21\3\2\2\2\u00b4\u00b5\5\n\6\2\u00b5\u00b6\7\r\2"+
		"\2\u00b6\u00b7\5\n\6\2\u00b7\u00b8\7\b\2\2\u00b8\23\3\2\2\2\u00b9\u00bd"+
		"\7\6\2\2\u00ba\u00bc\5\20\t\2\u00bb\u00ba\3\2\2\2\u00bc\u00bf\3\2\2\2"+
		"\u00bd\u00bb\3\2\2\2\u00bd\u00be\3\2\2\2\u00be\u00c0\3\2\2\2\u00bf\u00bd"+
		"\3\2\2\2\u00c0\u00c1\7\7\2\2\u00c1\25\3\2\2\2\u00c2\u00c3\7!\2\2\u00c3"+
		"\u00c4\7\3\2\2\u00c4\u00c5\5\n\6\2\u00c5\u00c6\7\5\2\2\u00c6\u00c7\5\20"+
		"\t\2\u00c7\27\3\2\2\2\u00c8\u00c9\7\"\2\2\u00c9\u00ca\7\3\2\2\u00ca\u00cb"+
		"\5\n\6\2\u00cb\u00cc\7\5\2\2\u00cc\u00cf\5\20\t\2\u00cd\u00ce\7#\2\2\u00ce"+
		"\u00d0\5\20\t\2\u00cf\u00cd\3\2\2\2\u00cf\u00d0\3\2\2\2\u00d0\31\3\2\2"+
		"\2\u00d1\u00d2\7\'\2\2\u00d2\u00d3\5\n\6\2\u00d3\u00d4\7\b\2\2\u00d4\33"+
		"\3\2\2\2\u00d5\u00d6\7(\2\2\u00d6\u00d7\5\n\6\2\u00d7\u00d8\7\b\2\2\u00d8"+
		"\35\3\2\2\2\u00d9\u00da\7%\2\2\u00da\u00db\5\n\6\2\u00db\u00dc\7\b\2\2"+
		"\u00dc\37\3\2\2\2\u00dd\u00de\5\n\6\2\u00de\u00df\7\16\2\2\u00df!\3\2"+
		"\2\2\u00e0\u00e1\5\n\6\2\u00e1\u00e2\7\17\2\2\u00e2#\3\2\2\2\22\'\60\63"+
		":@Lj\u008b\u008e\u0094\u0096\u009f\u00a2\u00b2\u00bd\u00cf";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}