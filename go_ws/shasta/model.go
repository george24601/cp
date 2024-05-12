package shasta

// ColumnInfo provides meta data describing of a table column.
type ColumnInfo struct {
	ID                  int64               `json:"id"`
	Name                string              `json:"name"`
	Offset              int                 `json:"offset"`
	OriginDefaultValue  interface{}         `json:"origin_default"`
	DefaultValue        interface{}         `json:"default"`
	GeneratedExprString string              `json:"generated_expr_string"`
	GeneratedStored     bool                `json:"generated_stored"`
	Dependencies        map[string]struct{} `json:"dependencies"`
	types.FieldType     `json:"type"`
	//	State               SchemaState `json:"state"`
	Comment string `json:"comment"`
}
