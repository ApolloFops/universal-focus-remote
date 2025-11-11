#include "eossyntaxhighlighter.h"

EosSyntaxHighlighter::EosSyntaxHighlighter(QTextDocument *parent) :
		QSyntaxHighlighter(parent) {
	HighlightingRule rule;

	modeFormat.setForeground(Qt::darkGray);
	rule.pattern = QRegularExpression(QStringLiteral("((LIVE)|(BLIND)|(Patch Channel)):\\s*((Cue)|(Park)|(Preset)|(Event)|(Magic Sheet)|(Setup))?(\\s|\\d)*((Staging Mode))*\\s*:"));
	rule.format = modeFormat;
	highlightingRules.append(rule);

	errorFormat.setForeground(Qt::red);
	rule.pattern = QRegularExpression(QStringLiteral("(Error:).+"));
	rule.format = errorFormat;
	highlightingRules.append(rule);
}

void EosSyntaxHighlighter::highlightBlock(const QString &text) {
	for (const HighlightingRule &rule : std::as_const(highlightingRules)) {
		QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
		while (matchIterator.hasNext()) {
			QRegularExpressionMatch match = matchIterator.next();
			setFormat(match.capturedStart(), match.capturedLength(), rule.format);
		}
	}
}
