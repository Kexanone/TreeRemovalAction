//------------------------------------------------------------------------------------------------
[BaseContainerProps()]
class TRA_DeleterStruct : SCR_JsonApiStruct
{
	protected ref array<vector> m_TRA_DeletedEntityPositions = {};
	
	//------------------------------------------------------------------------------------------------
	void TRA_DeleterStruct()
	{
		RegV("m_TRA_DeletedEntityPositions");
	}
	
	//------------------------------------------------------------------------------------------------
	override bool Serialize()
	{
		SCR_BaseGameMode gameMode = SCR_BaseGameMode.Cast(GetGame().GetGameMode());
		m_TRA_DeletedEntityPositions = gameMode.TRA_GetDeletedEntityPositions();
		return true;
	}
	
	//------------------------------------------------------------------------------------------------
	override bool Deserialize()
	{
		SCR_BaseGameMode gameMode = SCR_BaseGameMode.Cast(GetGame().GetGameMode());
		gameMode.TRA_LoadDeletedEntityPositions(m_TRA_DeletedEntityPositions);
		return true;
	}
	
	//------------------------------------------------------------------------------------------------
	void Clear()
	{
		m_TRA_DeletedEntityPositions.Clear();
	}
}