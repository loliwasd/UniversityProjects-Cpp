#include <QDir>
#include <QString>
#include <QDebug>

void countFilesAndFolders(const QString& path, int& fileCount, int& folderCount) {
    QDir dir(path);
    if (!dir.exists()) return;

    QFileInfoList entries = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);

    for (const QFileInfo& entry : entries) {
        if (entry.isDir()) {
            folderCount++;
            countFilesAndFolders(entry.absoluteFilePath(), fileCount, folderCount);
        } else if (entry.isFile()) {
            fileCount++;
        }
    }
}
