/** \class SourceFile
 * Represents a source code file
 *
 * @author  Christian Ammann (cammann@giants.ch)
 * @date  16/05/05
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _SOURCEFILE_H_
#define _SOURCEFILE_H_

#include <string>
#include <vector>

#include "FileType.h"
#include "SourceLine.h"

//class SourceLine;

class SourceFile {
protected:
    std::string m_fileName;
    FileType::FILETYPE m_FileType;

    static unsigned int m_minChars;
    static bool m_ignorePrepStuff;

    std::vector<SourceLine> m_sourceLines;

    int m_linesOfFile = 0;

	bool isSourceLine(const std::string& line);
	void getCleanLine(const std::string& line, std::string& cleanedLine);

public:
    SourceFile(const std::string& fileName );
    
    /**
     * @brief Get number of lines that are actual code
     *
     * @return number of lines of code
     */
    int getNumOfLinesOfCode() const;
    /**
     * @brief Get number of lines the file has
     *
     * @return number of lines the file has.
     */
    int getNumOfLinesOfFile( );
    const SourceLine& getLine(const int index) const;
    const std::string& getFilename() const;

    static void setMinChars( unsigned int a_min_chars );
    static void setIgnorePreprocessor( bool a_ignore );

private:

    void AddToLines( const std::string & tmp , int index );
    void RemoveBlockComments( const std::string & line , int & openBlockComments );
};

#endif
