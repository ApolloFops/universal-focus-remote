#include "qpatchdatamodel.h"

QPatchDataModel::QPatchDataModel(QObject *parent) :
		QAbstractTableModel(parent) {
}

QVariant QPatchDataModel::headerData(int section, Qt::Orientation orientation, int role) const {
	if (orientation == Qt::Orientation::Horizontal && role == Qt::ItemDataRole::DisplayRole) {
		switch (section) {
			case 0:
				return QString("Channel");
			case 1:
				return QString("Part");
			case 2:
				return QString("Address");
			case 3:
				return QString("Model");
			case 4:
				return QString("Label");
		}
	}

	return QVariant();
}

int QPatchDataModel::rowCount(const QModelIndex &parent) const {
	if (parent.isValid())
		return 0;

	return channelData.size();
}

int QPatchDataModel::columnCount(const QModelIndex &parent) const {
	if (parent.isValid())
		return 0;

	return 5;
}

bool QPatchDataModel::hasChildren(const QModelIndex &parent) const {
	return false;
}

bool QPatchDataModel::canFetchMore(const QModelIndex &parent) const {
	// FIXME: Implement me!
	return false;
}

void QPatchDataModel::fetchMore(const QModelIndex &parent) {
	// FIXME: Implement me!
}

QVariant QPatchDataModel::data(const QModelIndex &index, int role) const {
	if (!index.isValid())
		return QVariant();

	if (role == Qt::ItemDataRole::DisplayRole) {
		EosChannel *channel = channelData.value(channelOrder.value(index.row()));

		switch (index.column()) {
			case 0:
				return channel->channelNumber;
			case 1:
				return channel->partNumber;
			case 2:
				if (channel->address != 0) {
					return channel->address;
				} else {
					return QVariant();
				}
			case 3:
				return channel->fixtureModel;
			case 4:
				return channel->label;
		}
	}

	return QVariant();
}

void QPatchDataModel::setChannelData(QMap<QString, EosChannel *> channelData) {
	// TODO: Implement some more advanced logic here so that only items that changed get updated
	beginResetModel();

	this->channelData = channelData;

	QList<EosChannel *> inv;

	// Populate the inverted list
	for (EosChannel *channel : std::as_const(channelData)) {
		inv.append(channel);
	}

	std::sort(inv.begin(), inv.end(), EosChannel::compare);

	channelOrder.clear();
	channelOrder.squeeze();

	for (const EosChannel *channel : std::as_const(inv)) {
		channelOrder.append(channel->uid);
	}

	endResetModel();
}
