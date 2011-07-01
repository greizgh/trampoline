/**
 * @file tasks_s1_full/task2_instance.c
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

/*Instance of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareTask(t1);
DeclareTask(t2);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4;
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_1 = ActivateTask(t1);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OS_LIMIT, result_inst_1);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_2 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_LIMIT, result_inst_2);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_3 = ChainTask(t1);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OS_LIMIT, result_inst_3);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_4 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_4);
}

/*create the test suite with all the test cases*/
TestRef TaskManagementTest_seq1_t2_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance",test_t2_instance)
	};
	EMB_UNIT_TESTCALLER(TaskManagementTest,"TaskManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&TaskManagementTest;
}

/* End of file tasks_s1_full/task2_instance.c */
