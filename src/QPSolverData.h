// This file is part of Tasks.
//
// Tasks is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Tasks is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Tasks.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

// includes
// Tasks
#include "QPContacts.h"
#include <RBDyn/MultiBody.h>
#include <RBDyn/MultiBodyConfig.h>

namespace tasks
{

namespace qp
{


class SolverData
{
public:
	friend class QPSolver;

	SolverData();

	int nrVars() const
	{
		return nrVars_;
	}

	int alphaD() const
	{
		return alphaD_;
	}

	int lambda() const
	{
		return lambda_;
	}

	int torque() const
	{
		return torque_;
	}


	int alphaDBegin() const
	{
		return 0;
	}

	int lambdaBegin() const
	{
		return alphaD_;
	}

	int torqueBegin() const
	{
		return alphaD_ + lambda_;
	}


	int nrContacts() const
	{
		return static_cast<int>(uniCont_.size() + biCont_.size());
	}

	int nrUnilateralLambda() const
	{
		return lambdaUni_;
	}

	int nrBilateralLambda() const
	{
		return lambdaBi_;
	}

	int unilateralBegin() const
	{
		return alphaD_;
	}

	int bilateralBegin() const
	{
		return alphaD_ + lambdaUni_;
	}


	const std::vector<UnilateralContact>& unilateralContacts() const
	{
		return uniCont_;
	}

	const std::vector<BilateralContact>& bilateralContacts() const
	{
		return biCont_;
	}

	const rbd::MultiBody& manipBody() const
	{
		return manipBody_;
	}

	void manipBody(const rbd::MultiBody& body)
	{
		manipBody_ = body;
	}

	const rbd::MultiBodyConfig& manipBodyConfig() const
	{
		return manipBodyConfig_;
	}

	void manipBodyConfig(const rbd::MultiBodyConfig& bodyConfig)
	{
		manipBodyConfig_ = bodyConfig;
	}
	
	const std::vector<ManipContact>& robotToManipBodyContacts() const
	{
		return robotToManipBodyContacts_;
	}

	void robotToManipBodyContacts(const
			std::vector<ManipContact>& robToManiBodyCont)
	{
		robotToManipBodyContacts_ = robToManiBodyCont; 
	}

	const std::vector<ManipContact>& manipBodyToRobotContacts() const
	{
		return manipBodyToRobotContacts_;
	}

	void manipBodyToRobotContacts(const
			std::vector<ManipContact>& maniBodyToRobCont)
	{
		manipBodyToRobotContacts_ = maniBodyToRobCont; 
	}

	int nrContactsManip() const
	{
		return static_cast<int>(robotToManipBodyContacts_.size());
	} 

private:
	int alphaD_;
	int lambda_;
	int torque_;
	int nrVars_;

	int lambdaUni_;
	int lambdaBi_;

	std::vector<UnilateralContact> uniCont_;
	std::vector<BilateralContact> biCont_;

	int lambdaManip_;
	rbd::MultiBody manipBody_;
	rbd::MultiBodyConfig manipBodyConfig_;
	std::vector<ManipContact> robotToManipBodyContacts_;
	std::vector<ManipContact> manipBodyToRobotContacts_;
	
};


} // namespace qp

} // namespace tasks

